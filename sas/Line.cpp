#include "Line.h"

#include <iostream>

using namespace std;


 Line::Line(double mx, double my, double mxx, double myy){
	 x = mx;
	 xx = mxx;
	 y = my;
	 yy = myy;


}


void Line::draw() {
	/*
	
	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15, 0, 0);
	glEnd();
	*/

	glColor3f(0, 0, 0);
	glLineWidth(2);
	 glBegin(GL_LINES);
	 glVertex2f(x, y);
	 glVertex2f(xx, yy);
	 glEnd();
	 

 }