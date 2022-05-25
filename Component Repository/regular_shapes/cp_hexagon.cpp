#include<iostream>
#include<cmath>
#include"cp_shape.h"
#include"cp_hexagon.h"
#define pi 3.1415936535
using namespace std;
void cp_hexagon::get_length()
{
	length = double(side_numbers)*side_length;
	cout << "The perimeter of the regular hexagon is " << length << endl;
}
void cp_hexagon::get_area()
{
	area =side_length*side_length*sin(pi/3) / 2 * 6;
	cout << "The area of the regular hexagon is " << area << endl;
}