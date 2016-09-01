#include "circle.hpp"

Circle::Circle(unsigned int x, unsigned int y, double radius)
{
	//Why I cannot do this->x? 
	this->setPosition(x,y);
	this->setLenght(radius+1,radius+1);
	this->radius=radius;
}

Circle::~Circle()
{

}

bool Circle::draw(imagefile &image)
{
	//Let's draw a circle! 
	//All points must be less than
	//The norm of P(x,y) ||P||
	unsigned int circle_x;
	unsigned int circle_y;

	this->getPosition(circle_x,circle_y);

	printf("circle: (%i,%i) radius-> %f\n",circle_x,circle_y,radius);

	for (int i = circle_x-radius; i < circle_x+radius; ++i)
	{
		for (int j = circle_y-radius; j < circle_y+radius; ++j)
		{
			double x=circle_x;
			double y=circle_y;
			double norm = sqrt(pow(fabs(i-x),2)+pow(fabs(j-y),2));
			double rad_d=radius;
			
			if(norm<=rad_d){
				unsigned int pos = j*image.width+i;
				image.pixels[pos]=this->getColor();
			}	
		}
	}

	return 1;
}
