#ifndef IMAGE_OUT_HPP
#define IMAGE_OUT_HPP
#include <stdio.h>
#include <stdint.h>
//Define a pixel as a 3 bytes array

struct imagefile{
	unsigned int width;
	unsigned int height;
	uint32_t* pixels;
};

//Write function
bool writeImage(imagefile image, char* to_file);

#endif