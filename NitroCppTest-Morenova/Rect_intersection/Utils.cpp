#include "Utils.h"
#include <iostream>
#include "Rectangle.h"
#include "RectIntersection.h"
#include <iostream>
#include <fstream>

using json = nlohmann::json;
using namespace std;

namespace RectIntersection
{
	void OutputRectangles(std::ostream& output, const vector<shared_ptr<Rectangle>>& rectangles)
	{
		output << "Input:" << endl;
		for (size_t i = 0; i < rectangles.size(); ++i)
		{
			std::shared_ptr<Rectangle> thisRect = rectangles[i];

			output << '\t' << (i + 1) << ": Rectangle at " << thisRect->toString() << endl;
		}

		output << endl;
	}

	void OutputIntersections(std::ostream& output, const vector<shared_ptr<Intersection>> intersections)
	{
		output << "Intersections" << endl;

		for (int i = 0; i < intersections.size(); i++)
		{
			output << "\tBetween rectangle ";

			auto rectangleIndexes = intersections[i]->getRectangleIndexes();
			for (int j = 0; j < rectangleIndexes.size() - 2; j++)
			{
				output << rectangleIndexes[j]  << ", ";
			}
			output << rectangleIndexes[rectangleIndexes.size() - 2]  << " and ";
			output << rectangleIndexes[rectangleIndexes.size() - 1]  << " at ";
			output << intersections[i]->getIntersection()->toString() << endl;
		}
	}

	int read_json_file(string fileName, json& jsonRoot)
	{


		ifstream ifs(fileName, ifstream::in);


		if (ifs.is_open())
		{
			try
			{
				ifs >> jsonRoot;
			}
			catch (exception e)
			{
				cout << "Badly formed json input" << endl;

			}
			ifs.close();


			try
			{
				if (jsonRoot["rects"].size() <= 1)
				{
					throw std::invalid_argument("Json file should contain more than 1 record.");
					return -1;
				}


			}
			catch (nlohmann::detail::exception)
			{
				cout << "Problem parsing json input." << endl;
				return -1;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
		}
		else
		{
			cout << "Could not open json file : " << fileName << endl;
			return -1;
		}
		return 0;
	}
	
	vector<vector<int>> generate_pairs(int n) {
		vector<vector<int>> combinations;
		vector<int> current_combination;

		for (int first_elem = 1; first_elem < n; first_elem++) {
			for (int second_elem = first_elem + 1; second_elem <= n; second_elem++) {
				combinations.push_back(vector<int>({ first_elem, second_elem }));
			}
		}

		return combinations;
	}

	void generate_next(vector<vector<int>>& all_combinations, int prev_size, int max) {
		vector<vector<int>> new_combinations = vector<vector<int>>();

		for (vector<int> comb : all_combinations) {
			if (comb.size() == prev_size) {
				// in assumption that all integrers are ordeded in set. starting from next integrer
				for (int i = comb[comb.size() - 1] + 1; i <= max; i++) {
					vector<int> extended_combination = vector<int>(comb);
					extended_combination.push_back(i);
					new_combinations.push_back(extended_combination);
				}

			}
		}

		all_combinations.insert(all_combinations.end(), new_combinations.begin(), new_combinations.end());
	}

	vector<vector<int>> generate_all_combinations(int max) {
		vector<vector<int>> result = generate_pairs(max);
		for (int i = 2; i < max; i++) {
			generate_next(result, i, max);
		}

		return result;
	}
}

