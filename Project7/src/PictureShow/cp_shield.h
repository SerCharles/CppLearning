#ifndef CP_SHIELD_H
#define CP_SHIELD_H
#include"stdafx.h"
class cp_shield
{
public:
	double x, y, height, width;
	int r, g, b;
	cp_rectangle out;
public:
	void set(double a, double b, double h, double w, int t1, int t2, int t3);
	void draw(CDC* pDC);
};
#endif