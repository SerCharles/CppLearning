#ifndef CP_CIRCLE_H
#define CP_CIRCLE_H
#include"cp_shape.h"
class cp_circle :public cp_shape
{
public:
	double radius;
public:
	cp_circle(double l) :radius(l) {}
	~cp_circle() {}
public:
	void get_area();
	void get_length();
};











#endif