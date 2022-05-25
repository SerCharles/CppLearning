#ifndef CP_PANTAGON_H
#define CP_PANTAGON_H
#include"cp_shape.h"
class cp_pantagon :public cp_shape
{
public:
	int side_numbers;
	double side_length;
public:
	cp_pantagon(double l) :side_numbers(5), side_length(l) {}
	~cp_pantagon() {}
public:
	void get_area();
	void get_length();
};












#endif
