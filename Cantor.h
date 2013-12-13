#ifndef CANTOR_H
#define CANTOR_H

#include "Fractal.h"

//A class representing the cantor set
class Cantor: public Fractal
{
public:
	Cantor();
	virtual ~Cantor();

	virtual std::vector<Line> processLine(const Line& line) const;
};

#endif // CANTOR_H
