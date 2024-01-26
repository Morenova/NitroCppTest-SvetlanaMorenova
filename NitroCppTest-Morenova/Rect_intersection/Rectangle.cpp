#include "Rectangle.h"
#include <iostream>

using namespace std;
using json = nlohmann::json;

namespace RectIntersection
{
	Rectangle::Rectangle()
		: topLeftCorner(Point(0, 0)), width(0), height(0)
	{
	}

	Rectangle::Rectangle(Point topLeftCorner, int width, int height)
		: topLeftCorner(topLeftCorner), width(width), height(height)
	{
		if (width < 0 || height < 0)
		{
			throw std::invalid_argument("Width and height must be positive integers.");
		}
		if (topLeftCorner.getX() < 0 || topLeftCorner.getY() < 0)
		{
			throw std::invalid_argument("Coordinates must be positive integers.");
		}
		bottomRightCorner = Point(topLeftCorner.getX() + width, topLeftCorner.getY() + height);
	}

	Rectangle::Rectangle(Point topLeftCorner, Point bottomRightCorner)
		: topLeftCorner(topLeftCorner), bottomRightCorner(bottomRightCorner)
	{
		width = bottomRightCorner.getX() - topLeftCorner.getX();
		height = bottomRightCorner.getY() - topLeftCorner.getY();
	}

	Point Rectangle::getTopLeft() const
	{
		return topLeftCorner;
	}

	Point Rectangle::getBottomRight() const
	{
		return bottomRightCorner;
	}

	int Rectangle::getWidth() const
	{
		return width;
	}

	int Rectangle::getHeight() const
	{
		return height;
	}

	std::string Rectangle::toString() const
	{
		std::string ss1;
		ss1 = "(" + std::to_string(topLeftCorner.getX())+ "," + std::to_string( topLeftCorner.getY()) + "), w=" +
				std::to_string(width) + ", h=" +std::to_string( height) + ".";
		return ss1;
	}

	void from_json(const nlohmann::json& js, Rectangle& r)
	{
		int x, y, w, h;
		try
		{
			 x = js.at("x").get<int>();
			 y = js.at("y").get<int>();
			 w = js.at("w").get<int>();
			 h = js.at("h").get<int>();
			 r = Rectangle(Point(x, y), w, h);
		}
		catch (const json::exception& e)
		{
			cout << e.what() << '\n';
		}
		
		
	}
}