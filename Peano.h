#ifndef PEANO_H
#define PEANO_H

#include "Fractal.h"

class Peano: public Fractal
{
public:
	Peano();
	virtual ~Peano();

	virtual std::vector<Line> processLine(const Line& line) const;
};

#endif // PEANO_H
