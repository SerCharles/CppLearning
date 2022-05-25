#ifndef CP_TRIANGLE_H
#define CP_TRIANGLE_H

#include"stdafx.h"
class cp_triangle
{
public:
	double x, y, angle,length_lean,length_bottom;
	int r, g, b;
	cp_line line_lean_1, line_lean_2, line_bottom;
public:
	cp_triangle():x(0),y(0),angle(0),length_lean(0),length_bottom(0){}
	~cp_triangle(){}
	void set(double a,double b,double ang,double l_bottom, int t1, int t2, int t3);
	void draw(CDC* pDC);
};
#endif
