#include"stdafx.h"
#include<iostream>
void cp_line::set_place(double a, double b, double c, double d)
{
	begin.set(a, b);
	end.set(c, d);
}
void cp_line::set_color(int a1, int a2, int a3)
{
	r = a1; g = a2; b = a3;
}
