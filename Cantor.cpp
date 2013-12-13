#include "Cantor.h"

//#include <iostream>

Cantor::Cantor()
	:Fractal()
{
	//add the initial line to the cantor set
	set.push_back(Line(Point(-1, 0), Point(1, 0)));
}

Cantor::~Cantor()
{
}

// Splits a line in two smaller lines as expcted to format the cantor set
std::vector<Line> Cantor::processLine(const Line& line) const
{
	const Point &p0 = line.p0;
	const Point &pn = line.p1;
	const Point p1 = (pn-p0)/3.0f + p0;
	const Point p2 = ((pn-p0)*2.0f)/3.0f + p0;

	//debug output
	//std::cout << "processing line: " << line.toString() << std::endl;
	//std::cout << p0.toString() << " " << p1.toString() << " " << p2.toString() << " " << pn.toString() << std::endl;

	std::vector<Line> result;
	result.push_back(Line(p0, p1));
	result.push_back(Line(p2, pn));

	return result;
}
