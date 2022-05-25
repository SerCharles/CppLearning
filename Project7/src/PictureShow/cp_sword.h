#ifndef CP_SWORD_H
#define CP_SWORD_H

#include"stdafx.h"
class cp_sword
{
public:
	double x, y, angle, length;
	cp_rectangle body, handle_1, handle_2;
	cp_triangle blade;
public:
	void set(double a,double b,double ang,double len);
	void draw(CDC* pDC);
};
#endif
