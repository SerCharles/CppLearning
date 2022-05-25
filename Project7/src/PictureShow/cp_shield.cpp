#include"stdafx.h"
#include<iostream>
void cp_shield::set(double a, double b, double h, double w,int t1,int t2,int t3)
{
	x = a; y = b; height = h; width = w; r = t1; g = t2; b = t3;
	out.set(a, b, 0, w, h, r, g, b);
}
void cp_shield::draw(CDC* pDC)
{
	HGDIOBJ oldObj = pDC->SelectObject(GetStockObject(DC_BRUSH));
	COLORREF oldColor = pDC->SetDCBrushColor(RGB(r, g, b));
	pDC->Chord(x, y, x+width, y+height, x, y+height/2+1, x+width, y+height/2+1);
	pDC->SetDCBrushColor(oldColor);
	pDC->SelectObject(oldObj);
}