#include<iostream>
#include<cmath>
#include"cp_shape.h"
#include"cp_rectangle.h"
#define pi 3.1415936535
using namespace std;
void cp_rectangle::get_length()
{
	length = double(side_numbers)*side_length;
	cout << "The perimeter of the regular rectangle is " << length << endl;
}
void cp_rectangle::get_area()
{
	area = side_length * side_length;
	cout << "The area of the regular rectangle is " << area << endl;
}