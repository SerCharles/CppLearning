#ifndef CP_RECTANGLE_H
#define CP_RECTANGLE_H
#include"cp_shape.h"
class cp_rectangle :public cp_shape
{
public:
	int side_numbers;
	double side_length;
public:
	cp_rectangle(double l) :side_numbers(4),side_length(l) {}
	~cp_rectangle() {}
public:
	void get_area();
	void get_length();
};












#endif
