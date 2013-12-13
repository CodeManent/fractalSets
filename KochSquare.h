#ifndef KOCHSQUARE_H
#define KOCHSQUARE_H

#include "Koch.h"

class KochSquare: public Koch
{
public:
	KochSquare()
		:Koch()
	{
		const Point p0(-0.5f, 0.5f);
		const Point p1(0.5f, 0.5f);
		const Point p2(0.5f, -0.5f);
		const Point p3(-0.5f, -0.5f);

		set.clear();
		set.push_back(Line(p0, p1));
		set.push_back(Line(p1, p2));
		set.push_back(Line(p2, p3));
		set.push_back(Line(p3, p0));
	}
};

#endif // KOCHSQUARE_H
