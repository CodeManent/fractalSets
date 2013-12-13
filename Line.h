#ifndef LINE_H
#define LINE_H

#include <string>
#include <sstream>
#include <math.h>
#include <iostream>

#include "Point.h"

// A class Representing a line (segment)
class Line
{
public:

	Point p0, p1;
	Line(Point p0, Point p1): p0(p0), p1(p1){
	}

	// Adds two lines
	Line operator+(const Line& l2) const{
		return Line(p0 + l2.p0, p1 + l2.p1);
	}

	// Adds a line and a point. Equivalent of moving a line acording to the vector ((0,0), p)
	Line operator+(const Point &p) const{
		return Line(p0+p, p1+p);
	}

	// Applies the - operator on both of the line's members
	Line operator-() const{
		return Line(-p0, -p1);
	}

	// Substacts two lines
	Line operator-(const Line& l2) const {
		return Line(p0-l2.p0, p1-l2.p1);
	}

	//Subtracta a point from the line - moning the line
	Line operator-(const Point& p) const{
		return Line(p0-p, p1-p);
	}

	//Multiplies the members of the two lines
	Line operator*(const Line &l2) const {
		return Line(p0*l2.p0, p1 * l2.p1);
	}

	//Multiplies the members of the line with the number f
	Line operator*(const float f) const {
		return Line(p0*f, p1*f);
	}

	// Divides two lines member-by-member
	Line operator/(const Line& l2) const {
		return Line(p0/l2.p0, p1/l2.p1);
	}

	// Divides the members of the line by the number f
	Line operator/(const float f) const {
		return Line(p0/f, p1/f);
	}

	//Calculates the normal vector of the line segment.
	Point normal() const{
		const Point dp = p1 - p0;

		return Point(-dp.y, dp.x)/length();
	}

	// Returns the length of the line segment
	float length() const{
		return sqrt(pow(p1.x-p0.x, 2.0f) + pow(p1.y-p0.y, 2.0f));
	}

	// Returns a string pepresentation of the line segment in the form (x0, y0)-(x1, y1)
	std::string toString() const{
		std::stringstream ss;
		ss << p0.toString() << "-" << p1.toString();

		return ss.str();
	}
};

#endif // LINE_H
