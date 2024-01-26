#pragma once
#include <vector>
#include <memory>
#include <set>
#include "json.hpp"

using namespace std;

namespace RectIntersection
{
	class Rectangle;

	/* Class described intersection rectangle and correcponding indexis */

	class Intersection
	{
	private:
		vector<int> rectangleIndexes; 
		shared_ptr<Rectangle> intersection;
	public:
		Intersection() {};
		Intersection(vector<int> rectangleIndexes, shared_ptr<Rectangle> intersection)
			: rectangleIndexes(rectangleIndexes), intersection(intersection) {}

		vector<int> getRectangleIndexes() const { return rectangleIndexes; }

		shared_ptr<Rectangle> getIntersection() const { return intersection; }
	};

	class RectIntersection
	{
	private:
		vector<shared_ptr<Rectangle>> rectangles;

		void parseFromJson(const nlohmann::json& rectanglesJsonArray);

		void generateIntersections( vector<vector<int>>& intersectionIndexes,
			vector<shared_ptr<Intersection>>& intersections) const;

	public:
		RectIntersection(const nlohmann::json& rectanglesJsonArray);
		static const int MAX_RECTANGLE_COUNT;

		int getCount() const;
		shared_ptr<Rectangle> getRectangle(int index) const;

		const std::vector<std::shared_ptr<Rectangle>>& getRectangles() const;
		std::vector<std::shared_ptr<Intersection>> getIntersections() const;

		
	};
}