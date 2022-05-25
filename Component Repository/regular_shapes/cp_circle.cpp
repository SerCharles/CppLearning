#include<iostream>
#include<cmath>
#include"cp_shape.h"
#include"cp_circle.h"
#define pi 3.1415936535
using namespace std;
void cp_circle::get_length()
{
	length = 2*pi*radius;
	cout << "The perimeter of the circle is " << length << endl;
}
void cp_circle::get_area()
{
	area = pi*radius*radius;
	cout << "The area of the circle is " << area << endl;
}