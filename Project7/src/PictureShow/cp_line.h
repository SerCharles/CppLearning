#ifndef CP_LINE_H
#define CP_LINE_H
#include"cp_point.h"
class cp_line
{
public:
	cp_point begin; 
	cp_point end;
	int r, g, b;
public:
	cp_line():r(0),g(0),b(0){}
	~cp_line(){}
	void set_place(double a, double b, double c, double d);
	void set_color(int a1, int a2, int a3);
};
#endif
