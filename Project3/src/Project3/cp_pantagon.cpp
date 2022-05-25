#include<iostream>
#include<cmath>
#include"cp_shape.h"
#include"cp_pantagon.h"
#define pi 3.1415936535
using namespace std;
void cp_pantagon::get_length()
{
	length = double(side_numbers)*side_length;
	cout << "The perimeter of the regular pantagon is " << length << endl;
}
void cp_pantagon::get_area()
{
	double h = side_length / 2 / tan(pi / 5);
	area = h * side_length / 2 * 5;
	cout << "The area of the regular pantagon is " << area << endl;
}