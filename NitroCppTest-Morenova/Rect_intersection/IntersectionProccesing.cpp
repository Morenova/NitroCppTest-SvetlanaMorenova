#include "Rectangle.h"
#include "IntersectionProccesing.h"
#include "limits.h"

using namespace std;
namespace RectIntersection
{

	shared_ptr<Rectangle> getIntersectionRectangle(const vector<shared_ptr<Rectangle>> rectangles)
	{	
		int leftCornerX = INT_MIN, tmp_leftCornerX= 0;
		int rightCornerX = INT_MAX, tmp_rightCornerX = 0;
		int leftCornerY = INT_MIN, tmp_leftCornerY = 0;
		int rightCornerY = INT_MAX, tmp_rightCornerY = 0;

		for (auto& rect : rectangles)
		{
			Point rectTL = rect->getTopLeft();
			Point rectBR = rect->getBottomRight();
			bool first_entrty = false;

			tmp_leftCornerX = max(leftCornerX, rectTL.getX());
			tmp_rightCornerX = min(rightCornerX, rectBR.getX());
			tmp_leftCornerY = max(leftCornerY, rectTL.getY());
			tmp_rightCornerY = min(rightCornerY, rectBR.getY());
			if (!(tmp_leftCornerX > tmp_rightCornerX || tmp_leftCornerY > tmp_rightCornerY ))
			{
				leftCornerX = tmp_leftCornerX;
				rightCornerX = tmp_rightCornerX;
				leftCornerY = tmp_leftCornerY;
				rightCornerY = tmp_rightCornerY;
				first_entrty = true;
			}
			else {
				if (!first_entrty)
					return NULL;
			}
		}

		return make_shared<Rectangle>(Point(leftCornerX, leftCornerY), Point(rightCornerX, rightCornerY));
	}


}

