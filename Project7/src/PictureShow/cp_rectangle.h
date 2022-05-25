#ifndef CP_RECTANGLE_H
#define CP_RECTANGLE_H
#include"stdafx.h"

class cp_rectangle
{
public:
	double x, y, angle, length_lean, length_bottom;
	int r, g, b;
	cp_line line_lean_1, line_lean_2, line_bottom_1,line_bottom_2;
public:
	cp_rectangle() :x(0), y(0), angle(0), length_lean(0), length_bottom(0) {}
	~cp_rectangle() {}
	void set(double a, double b, double ang, double l_bottom,double l_lean, int t1, int t2, int t3);
	void draw(CDC* pDC);
};
#endif
