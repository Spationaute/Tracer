#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <vector>
#include <math.h>
#include "shape.hpp"
#include "imageout.hpp"

using namespace std;

class Canvas
{
public:
	Canvas();
	~Canvas();

	void setName(char* file);
	char* getName();

	void setDimension(unsigned int width,unsigned int height);
	void getDimension(unsigned int &width,unsigned int &height);

	int appendShape(Shape* to_append);

	bool write();

private:
	vector<Shape*> shape_array;
	char* file_name;
	unsigned int width;
	unsigned int height;
};

#endif