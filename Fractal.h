#ifndef FRACTAL_H
#define FRACTAL_H


#include <vector>
#include <string>

#include "Line.h"
#include "Point.h"

class Fractal
{
public:
	Fractal();
	virtual ~Fractal();

	// Method applying the fractal function that creates the next level of the fractal.
	virtual void step();

	virtual const std::vector<Line> &getLines() const;
	virtual std::string toString() const;

	virtual std::vector<Line> processLine(const Line& line) const = 0;

protected:
	std::vector<Line> set;
};

#endif // FRACTAL_H
