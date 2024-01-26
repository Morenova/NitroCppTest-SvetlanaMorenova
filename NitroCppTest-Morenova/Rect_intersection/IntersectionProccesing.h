#pragma once
#include <vector>
#include <memory>

using namespace std;

namespace RectIntersection
{
	class Rectangle;

	/* Get parameters of intersection area */
	shared_ptr<Rectangle> getIntersectionRectangle(const vector<shared_ptr<Rectangle>> rectangles);
}