#include "canvas.hpp"
Canvas::Canvas(){ 
	//File name point toward NULL (Nothing)
	file_name=NULL;
}

Canvas::~Canvas(){ 

}


void Canvas::setName(char* file){ 
	file_name=file;
}

char* Canvas::getName(){ 
	if(file_name==NULL){
		return NULL;
	}
	return file_name;
}


void Canvas::setDimension(unsigned int width,unsigned int height){ 
	this->width=width;
	this->height=height;
}

void Canvas::getDimension(unsigned int &width,unsigned int &height){ 
	width=this->width;
	height=this->height;
}

int Canvas::appendShape(Shape* to_append){
	//Vector are neat. Aren't they? 
	shape_array.push_back(to_append);
}

bool Canvas::write(){ 
	//Test is the file is specified
	if(file_name==NULL){
		return 0;
	}

	imagefile image;
	image.width=width;
	image.height=height;
	//Draw a dark background
	uint32_t pixels[width*height];
	for (int i = 0; i < width*height; ++i)
	{
		pixels[i]=0x000000;
	}

	image.pixels=pixels;

	//Draw the shape on the canvas, 
	//first in first out. (FIFO)
	for (int i = 0; i < shape_array.size(); ++i)
	{
		//All shape have a virtual image function
		shape_array[i]->draw(image);
	}

	//If image is written
	if(writeImage(image,file_name)){

		//All is ok! 
		return 1;
	}

	//A bug crawl there...
	return 0;
}
