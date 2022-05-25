#include<iostream>
#include<cmath>
#include"stdafx.h"
void cp_rectangle::set(double a, double b, double ang, double l_bottom,double l_lean, int t1, int t2, int t3)
{
	x = a; y = b; angle = ang;  length_bottom = l_bottom; r = t1; g = t2; b = t3;
	length_lean = l_lean;
	double dx, dy, tx, ty;
	dx = length_bottom * sin(ang);
	dy = 0 - length_bottom * cos(ang);
	tx = length_lean * cos(ang);
	ty = length_lean * sin(ang);
	line_bottom_1.set_place(x, y, x + dx, y + dy);
	line_bottom_1.set_color(r, g, b);
	line_bottom_2.set_place(x+tx, y+ty, x + dx+tx, y + dy+ty);
	line_bottom_2.set_color(r, g, b);
	line_lean_1.set_place(x, y, x+tx, y+ty);
	line_lean_1.set_color(r, g, b);
	line_lean_2.set_place(x + dx +tx, y  +dy+ ty, x + dx, y + dy);
	line_lean_2.set_color(r, g, b);
}
void cp_rectangle::draw(CDC* pDC)
{
	CPoint pts[4];
	pts[0].x = line_lean_1.begin.x; pts[0].y = line_lean_1.begin.y;
	pts[1].x = line_lean_1.end.x; pts[1].y = line_lean_1.end.y;
	pts[2].x = line_lean_2.begin.x; pts[2].y = line_lean_2.begin.y;
	pts[3].x = line_lean_2.end.x; pts[3].y = line_lean_2.end.y;
	CPen pen_grey(PS_SOLID, 5, RGB(r, g, b));
	CPen* pOldPen = pDC->SelectObject(&pen_grey);
	CBrush brush(RGB(r, g, b));
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Polygon(pts, 4);

	// Put back the old objects.
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}