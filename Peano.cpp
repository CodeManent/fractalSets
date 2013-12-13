#include "Peano.h"

Peano::Peano()
	:Fractal()
{
	//add the initial line to the peano set
	set.push_back(Line(Point(-1, 0), Point(1, 0)));
}

Peano::~Peano()
{
}

// Splits a line in two smaller lines as expcted to format the cantor set
std::vector<Line> Peano::processLine(const Line &line) const
{
	const Point &p0 = line.p0;
	const Point &pn = line.p1;

	const Point p1 = (pn-p0)/3.0f + p0;
	const Point p4 = ((pn-p0)*2.0f)/3.0f + p0;

	const Point pnorm = line.normal()*(line.length()/3.0f);
	const Point p2 = p1 + pnorm;
	const Point p3 = p4 + pnorm;
	const Point p5 = p1;
	const Point p6 = p1 - pnorm;
	const Point p7 = p4 - pnorm;
	const Point p8 = p4;

	//debug output
	//std::cout << "processing line: " << line.toString()<< std::endl;
	//std::cout << p0.toString() << " " << p1.toString() << " " << p2.toString() << " " << pn.toString() << std::endl;
	//std::cout << "Length = " << line.length() << std::endl;


	std::vector<Line> result;
	result.push_back(Line(p0, p1));
	result.push_back(Line(p1, p2));
	result.push_back(Line(p2, p3));
	result.push_back(Line(p3, p4));
	result.push_back(Line(p4, p5));
	result.push_back(Line(p5, p6));
	result.push_back(Line(p6, p7));
	result.push_back(Line(p7, p8));

	result.push_back(Line(p8, pn));

	return result;
}
