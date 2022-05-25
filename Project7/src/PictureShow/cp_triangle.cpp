#include<iostream>
#include<cmath>
#include"stdafx.h"
void cp_triangle::set(double a, double b, double ang, double l_bottom,int t1,int t2,int t3)
{
	x = a; y = b; angle = ang;  length_bottom = l_bottom; r = t1; g = t2; b = t3;
	length_lean = sqrt(5) / 2 * length_bottom;
	double dx, dy,tx,ty;
	dx = length_bottom * sin(ang);
	dy = 0-length_bottom * cos(ang);
	tx = length_bottom * cos(ang);
	ty= length_bottom * sin(ang);
	line_bottom.set_place(x, y, x + dx, y + dy);
	line_bottom.set_color(r, g, b);
	line_lean_1.set_place(x, y, x + dx / 2 + tx, y + dy / 2 + ty);
	line_lean_1.set_color(r, g, b);
	line_lean_2.set_place(x + dx / 2 + tx, y + dy / 2 + ty, x + dx, y + dy);
	line_lean_2.set_color(r, g, b);
}
void cp_triangle::draw(CDC* pDC)
{
	CPoint pts[3];
	pts[0].x = line_lean_1.begin.x; pts[0].y = line_lean_1.begin.y;
	pts[1].x = line_lean_2.begin.x; pts[1].y = line_lean_2.begin.y;
	pts[2].x = line_lean_2.end.x; pts[02].y = line_lean_2.end.y;
	CPen pen_grey (PS_SOLID, 5, RGB(r, g, b));
	CPen* pOldPen = pDC->SelectObject(&pen_grey);
	CBrush brush(RGB(r, g, b));
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Polygon(pts, 3);

	// Put back the old objects.
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}