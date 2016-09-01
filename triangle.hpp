#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include <math.h>

class Circle : public Shape
{

public:
	Circle(unsigned int x, unsigned int y, double radius);
	~Circle();

	//Implementation of
	//the draw function
	bool draw(imagefile &image);

private:
	double radius;
	
};
#endif