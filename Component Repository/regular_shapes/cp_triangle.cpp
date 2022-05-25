#include<iostream>
#include<cmath>
#include"cp_shape.h"
#include"cp_triangle.h"
#define pi 3.1415936535
using namespace std;
void cp_triangle::get_length()
{
	length = double(side_numbers)*side_length;
	cout << "The perimeter of the regular triangle is " << length << endl;
}
void cp_triangle::get_area()
{
	area = side_length * side_length*sin(pi*(side_numbers - 2) / 3) / 2;
	cout << "The area of the regular triangle is " << area << endl;
}