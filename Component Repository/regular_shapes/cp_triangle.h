#ifndef CP_TRIANGLE_H
#define CP_TRIANGLE_H
#include"cp_shape.h"
class cp_triangle :public cp_shape
{
public:
	int side_numbers;
	double side_length;
public:
	cp_triangle(double l):side_numbers(3),side_length(l){}
	~cp_triangle() {}
public:
	void get_area();
	void get_length();
};
#endif
