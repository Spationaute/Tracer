#include "shape.hpp"

Shape::Shape()
{
	x=0;
	y=0;
	w=0;
	h=0;
	color=0x000000;
}

Shape::~Shape()
{

}

bool Shape::setPosition(unsigned int x,unsigned int y)
{
	this->x=x;
	this->y=y;

}

bool Shape::setLenght(unsigned int w,unsigned int h)
{
	this->w=w;
	this->h=h;

}

void Shape::getPosition(unsigned int &x,unsigned int &y)
{
	x=this->x;
	y=this->y;
}

void Shape::getLenght(unsigned int &w,unsigned int &h)
{
	w=this->w;
	h=this->h;
}

void Shape::setColor(uint32_t color)
{
	this->color=color;
}

uint32_t Shape::getColor()
{
	return this->color;
}

//No definition for "virtual bool Shape::draw(imagefile &image)"

