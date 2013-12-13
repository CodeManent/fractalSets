#include "Koch.h"
#include <math.h>

Koch::Koch(float a)
	: Fractal()
	, a(a)
{
	set.push_back(Line(Point(-1, -0.75f), Point(1, -0.75f)));
}

Koch::~Koch()
{
}

std::vector<Line> Koch::processLine(const Line &line) const
{
	static const double factor = sqrt(3.0f)/2.0f;
	const Point &p0 = line.p0;
	const Point &pn = line.p1;

	const Point p = (pn - p0)*(1.0f - a)/2.0f;
	const Point p1 = p0 + p;
	const Point p3 = pn - p;
	const Point pheight = Line(p1, p3).normal() * factor * (line * a).length();
	const Point p2 = (p1+p3)/2.0f + pheight;



	std::vector<Line> result;
	result.push_back(Line(p0, p1));
	result.push_back(Line(p1, p2));
	result.push_back(Line(p2, p3));
	result.push_back(Line(p3, pn));

	return result;
}
