#include<iostream>
#include<cmath>
#include"stdafx.h"
void cp_sword::set(double a, double b, double ang, double len)
{
	x = a; y = b; angle = ang; length = len;
	body.set(x, y, angle, len, 8 * len, 41, 36, 33);
	double x1 = body.line_bottom_2.begin.x, y1 = body.line_bottom_2.begin.y;
	double x2 = x - (len / 4)*cos(angle)-(len/2)*sin(angle), y2 = y - (len / 4)*sin(angle)+(len/2)*cos(angle);
	double x3 = x - (len * 2)*cos(angle) + (len / 6)*sin(angle), y3 = y - (len * 2)*sin(angle) - (len / 6)*cos(angle);
	blade.set(x1, y1, angle,len, 41, 36, 33);
	handle_1.set(x2, y2, angle, len * 2, len / 4, 128, 128, 105);
	handle_2.set(x3, y3, angle, len * 2 / 3, len * 7 / 4, 128, 128, 105);
}
void cp_sword::draw(CDC* pDC)
{
	body.draw(pDC);
	blade.draw(pDC);
	handle_1.draw(pDC);
	handle_2.draw(pDC);
}