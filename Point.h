#ifndef POINT_H
#define POINT_H
#include <sstream>
#include <string>

// A class reptesenting a 2D point
class Point
{
public:

	float x, y;
	Point(float x, float y):x(x), y(y){
	}

	// Adds two points
	Point operator+(const Point& p2) const {
		return Point(x+p2.x, y+p2.y);
	}

	// returns the "inverse "negative" point
	Point operator-() const{
		return Point(-x, -y);
	}

	// Subtracts two points
	Point operator-(const Point& p2) const {
		return Point(x-p2.x, y-p2.y);
	}

	// Multiplies two points
	Point operator*(const Point& p2) const {
		return Point(x*p2.x, y*p2.y);
	}

	//Multiplies a point with a number
	Point operator*(const float f) const {
		return Point(x*f, y*f);
	}

	// Divides two points
	Point operator/(const Point&p2) const {
		return Point(x/p2.x, y/p2.y);
	}

	// Divides a point with a minber
	Point operator/(const float f) const {
		return Point(x/f, y/f);
	}

	// Returns a string representation of the point in the form (x, y)
	std::string toString() const{
		std::stringstream ss;

		ss << '(' << x << ", " << y << ')';

		return ss.str();
	}

};

#endif // POINT_H
