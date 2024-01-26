#pragma once
#include "Rectangle.h"
#include "Point.h"

using namespace std;

namespace RectIntersection
{
	class Rectangle;
	class Intersection;

	// Print input rectangles in the following format:
    //	Input:
	//		1 : Rectangle at(10, 720), w = 50, h = 10.
	//		2 : Rectangle at(10, 730), w = 50, h = 10.

	void OutputRectangles(ostream& output, const vector<shared_ptr<Rectangle>>& rectangles);

	//  Print rectangles intersection in the following format:
	//  Intersections
    //    Between rectangle 1 and 2 at (10,730), w=50, h=0.

	void OutputIntersections(ostream& output, const vector<shared_ptr<Intersection>> intersections);

	// Read json file with coordinate

	int read_json_file(string fileName, nlohmann::json& jsonRoot);

	vector<vector<int>> generate_pairs(int n);
    void generate_next(vector<vector<int>>& all_combinations, int prev_size, int max);
    vector<vector<int>> generate_all_combinations(int max);
}

