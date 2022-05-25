#ifndef CP_HEXAGON_H
#define CP_HEXAGON_H
#include"cp_shape.h"
class cp_hexagon :public cp_shape
{
public:
	int side_numbers;
	double side_length;
public:
	cp_hexagon(double l) :side_numbers(6), side_length(l) {}
	~cp_hexagon() {}
public:
	void get_area();
	void get_length();
};












#endif
