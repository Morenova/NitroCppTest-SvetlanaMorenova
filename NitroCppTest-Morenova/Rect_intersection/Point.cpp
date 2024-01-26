#include "Point.h"

namespace RectIntersection
{
	Point::Point()
	{
		x = 0;
		y = 0;
	}

	Point::Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int Point::getX() const
	{
		return x;
	}

	int Point::getY() const
	{
		return y;
	}

	bool Point::operator==(const Point& obj)
	{
		return x == obj.x && y == obj.y;
	}

	bool Point::operator!=(const Point& obj)
	{
		return !(*this == obj);
	}
}