#pragma once
#include "json.hpp"
#include "Point.h"

/// <summary>
/// Class Rectangle describes rictangle with coordinate (x,y) in the top left corner,
/// a width and height value.Widthand height are integers that are never negative
/// </summary>
namespace RectIntersection
{
	class Rectangle
	{
	private:
		Point topLeftCorner;
		Point bottomRightCorner;
		int width;
		int height;

	public:
		Rectangle();
		Rectangle(Point position, int width, int height);
		Rectangle(Point topLeftCorner, Point bottomRightCorner);

		Point getTopLeft() const;
		Point getBottomRight() const;

		int getWidth() const;
		int getHeight() const;

		static bool is_Equal(Rectangle& a, Rectangle& b);
		bool is_EqualtoAnother(Rectangle& a);
		std::string toString() const;
	};

	void from_json(const nlohmann::json& j, Rectangle& p);
}