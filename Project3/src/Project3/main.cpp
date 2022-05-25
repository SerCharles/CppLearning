#include<iostream>
#include"cp_shape.h"
#include"cp_circle.h"
#include"cp_triangle.h"
#include"cp_rectangle.h"
#include"cp_pantagon.h"
#include"cp_hexagon.h"
#include"cp_integer.h"
#include"test.h"
#define end_turn 1000000000
using namespace std;
cp_shape* list[3000] = { 0 };
int sum = 0;
int getnum()
{
	cp_integer* n = new cp_integer();
	while (1)
	{
		n->integer_input();
		if (n->num <= 0) cout << "Invalid input, please try again." << endl;
		else
		{
			int a = n->num;
			delete(n);
			return a;
		}
	}
}
int main(int argc, char* argv[])
{
	//test(); //µ¥Ôª²âÊÔ
	while (1)
	{
		cp_integer* a = new cp_integer();
		a->integer_input();
		if (a->num < 0||a->num>=6)
		{
			cout << "Invalid input, please try again." << endl;
			delete(a);
		}
		else if (a->num == 0)
		{
			delete(a);
			double area_sum = 0, length_sum = 0;
			for (int i = 1; i <= sum; i++)
			{
				area_sum += list[i]->area;
				length_sum += list[i]->length;
				delete(list[i]);
			}
			cout << "The number of the shapes is " << sum << endl;
			cout << "The total perimeter of the shapes is " << length_sum << endl;
			cout << "The total area of the shapes is " << area_sum << endl;
			cout << "Ready to leave the project" << endl;
			break;
		}
		else
		{
			sum++;
			if (a->num != 5) cout << "Now please input the length of its sides" << endl;
			else cout << "Now please input its radius" << endl;
			if (a->num == 1)
			{
				cp_triangle* s = new cp_triangle(double(getnum()));
				s->get_length();
				s->get_area();
				list[sum] = s;
			}
			if (a->num == 2)
			{
				cp_rectangle* s = new cp_rectangle(double(getnum()));
				s->get_length();
				s->get_area();
				list[sum] = s;
			}
			if (a->num == 3)
			{
				cp_pantagon* s = new cp_pantagon(double(getnum()));
				s->get_length();
				s->get_area();
				list[sum] = s;
			}
			if (a->num == 4)
			{
				cp_hexagon* s = new cp_hexagon(double(getnum()));
				s->get_length();
				s->get_area();
				list[sum] = s;
			}
			if (a->num == 5)
			{
				cp_circle* s = new cp_circle(double(getnum()));
				s->get_length();
				s->get_area();
				list[sum] = s;
			}	
		}
	}
	for (int i = 1; i <= end_turn; i++);
	return 0;
}