#ifndef KOCH_H
#define KOCH_H

#include "Fractal.h"

class Koch : public Fractal
{
public:
	Koch(float a = 1.0f/3.0f);
	virtual ~Koch();

	virtual std::vector<Line> processLine(const Line &line) const;

	float getA() const;

private:
	float a;
};

#endif // KOCH_H
