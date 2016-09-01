#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <stdint.h>
#include "imageout.hpp"

class Shape
{
public:
	Shape();
	~Shape();

	//All class will return position
	bool setPosition(unsigned int x,unsigned int y);
	void getPosition(unsigned int &x,unsigned int &y);

	//All class will return width and height
	bool setLenght(unsigned int w,unsigned int h);
	void getLenght(unsigned int &w,unsigned int &h);

	void setColor(uint32_t color);
	uint32_t getColor();

	//Purly virtual function
	//All class MUST have this function
	virtual bool draw(imagefile &image) = 0;

private:
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;

protected:
	uint32_t color;
};

#endif