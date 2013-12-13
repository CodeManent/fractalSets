#include "Fractal.h"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>

//A typedef to help ease the iteration of fractal's lines.
typedef std::vector<Line>::const_iterator line_iterator;



Fractal::Fractal()
{
}

Fractal::~Fractal()
{
}

// Gets the next generation of the cantor set
void Fractal::step()
{
	std::vector<Line> newSet;

	//For every line in the set
	for(line_iterator line = set.begin(); line != set.end(); ++line)
	{
		//transform it (splitting in two smaller lines
		std::vector<Line> newLines = processLine(*line);

		//and at them to the result
		std::copy(newLines.begin(), newLines.end(), std::back_inserter(newSet));
	}

	// and finally make the new set to be the current one (by switcing data)
	newSet.swap(set);
}





// Returns the set
const std::vector<Line> &Fractal::getLines() const
{
	return set;
}


std::string Fractal::toString() const
{
	std::stringstream ss;

	for(line_iterator line = set.begin(); line != set.end(); ++line)
	{
		ss << line->toString() << std::endl;
	}

	return ss.str();
}
