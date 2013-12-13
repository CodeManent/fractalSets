#ifndef KOCHTRIANGLE_H
#define KOCHTRIANGLE_H

#include "Koch.h"

class KochTriangle: public Koch
{
public:

	//Creates a triangle and set is as the base for the fractal
	KochTriangle(float a = 1.0f/3.0f)
		:Koch(a)
	{
		set.clear();

		//set the base points
		Point p0(-0.75, -0.25);
		Point p2(0.75, -0.25);

		// Calculate the top point
		Line base(p0, p2);
		Point p1 = (p0+p2)/2.0f + base.normal()*sqrt(3.0f)/2;

		//find the center of the shape
		Point center = (p0+p1+p2)/3.0f;

		//move the shape to the center of the screen
		p0 = p0 - center;
		p1 = p1 - center;
		p2 = p2 - center;

		// add the final shape to the fractal
		set.push_back(Line(p0, p1));
		set.push_back(Line(p1, p2));
		set.push_back(Line(p2, p0));
	}

	virtual ~KochTriangle()
	{
	}
};

#endif // KOCHTRIANGLE_H
