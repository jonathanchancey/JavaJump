#ifndef Line_h
#define Line_h

#include <stdio.h>
#include <vector>


#include "GlutApp.h"

//^stuff needed for draw

class Line{
	double x, xx, y, yy;
	
public:

	void draw();

	  Line(double, double, double, double);

};

#endif
//#pragma once

