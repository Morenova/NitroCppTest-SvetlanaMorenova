// RectIntersection_App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <json.hpp>
#include "RectIntersection.h"
#include "Utils.h"
#include <set>

using json = nlohmann::json;
using namespace std;

#include <vector>
#include <set>

using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Missing rectangle json file name" << endl << "Usage : <FileName>" << endl;
		return -1;
	}

	string fileName = argv[1];
	json jsonRoot;

	int result = 0;

	result = RectIntersection::read_json_file(fileName, jsonRoot);
	if (result)
		return -1;

	RectIntersection::RectIntersection RectIntersection(jsonRoot["rects"]);

	OutputRectangles(std::cout, RectIntersection.getRectangles());
	OutputIntersections(std::cout, RectIntersection.getIntersections());



	return 0;

}