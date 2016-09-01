#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <stdio.h>
#include "shape.hpp"
#include "canvas.hpp"
#include "circle.hpp"

int main(){
	Canvas canvas;
	canvas.setName("test.ppm");
	canvas.setDimension(640,480);
	abug	
	Circle circle_a(320,240,210);
	circle_a.setColor(0xFFFFFF);
	canvas.appendShape(&circle_a);
	
	Circle circle_b(320,240,200);
	circle_b.setColor(0xFFFF00);
	canvas.appendShape(&circle_b);

	canvas.write();
	return 0;
}
