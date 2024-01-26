#include "RectIntersection.h"
#include "Rectangle.h"
#include "IntersectionProccesing.h"
#include "json.hpp"
#include <iostream>
#include "Utils.h"
#include <set>

using namespace std;

namespace RectIntersection
{

	using json = nlohmann::json;

	const int RectIntersection::MAX_RECTANGLE_COUNT = 10;

	RectIntersection::RectIntersection(const json& rectanglesJsonArray)
	{
		parseFromJson(rectanglesJsonArray);
	}

	void RectIntersection::parseFromJson(const json& rectanglesJsonArray)
	{
		int count = min((int)rectanglesJsonArray.size(), MAX_RECTANGLE_COUNT);

		rectangles.reserve(count);

			for (int i = 0; i < count; i++)
			{
				auto rectangle = shared_ptr<Rectangle>(new Rectangle(rectanglesJsonArray[i]));
				rectangles.push_back(rectangle);
			}

	}

	int RectIntersection::getCount() const
	{
		return rectangles.size();
	}

	shared_ptr<Rectangle> RectIntersection::getRectangle(int index) const
	{
		return rectangles.at(index);
	}

	const vector<shared_ptr<Rectangle>>& RectIntersection::getRectangles() const
	{
		return rectangles;
	}

	void RectIntersection::generateIntersections(vector<vector<int>>& intersectionIndexes,
		vector<shared_ptr<Intersection>>& intersections) const
	{
		vector<vector<int>> combinations = generate_all_combinations(intersectionIndexes.size());


		for (size_t setIndex = 0; setIndex < combinations.size(); ++setIndex)
		{
			vector<int> set = combinations[setIndex];
			vector<shared_ptr<Rectangle>> rects;
			for (rsize_t i = 0; i < set.size(); i++)
			{
				// indexes are generated in 1..n format. convering back to vector indexes
				rects.push_back(rectangles[set[i]-1]);
			}
			auto intersectionRectangle = getIntersectionRectangle(rects);
			if (intersectionRectangle != NULL) {
				auto intersection = make_shared<Intersection>(set, intersectionRectangle);
				intersections.push_back(intersection);
			}
		}

	}

	vector<shared_ptr<Intersection>> RectIntersection::getIntersections() const
	{
		std::vector<std::vector<int>> intersectionIndexes;
		intersectionIndexes.resize(rectangles.size());

		vector<shared_ptr<Intersection>> intersections;
		generateIntersections(intersectionIndexes, intersections);

		return intersections;
	}
}