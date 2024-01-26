#pragma once
/// <summary>
/// Class Point describes point with coordinate (x,y)
/// </summary>
namespace RectIntersection
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point();
		Point(int x, int y);

		int getX() const;
		int getY() const;

		bool operator==(const Point& other);
		bool operator!=(const Point& other);
	};
}