#include<iostream>
#include<fstream>
#include"cp_shape.h"
#include"cp_circle.h"
#include"cp_triangle.h"
#include"cp_rectangle.h"
#include"cp_pantagon.h"
#include"cp_hexagon.h"
#include"cp_integer.h"
#include"cp_unit_test.h"
using namespace std;
ifstream data_file("data.txt");
void test()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
				double num, pari, area;
				data_file >> num >> pari >> area;
				if (i == 1)
				{
					cp_triangle* a = new cp_triangle(num);
					a->get_area(); a->get_length();
					cp_unit_test* b = new cp_unit_test(a->length, pari, 0.001);
					cp_unit_test* c = new cp_unit_test(a->area, area, 0.001);
					cout << "The output perimeter is " << a->length << ", the right answer is " << pari<<endl;
					cout << "The output area is " << a->area << ", the right answer is " << area<< endl;
					if (b->compare() && c->compare()) cout << "Right Answer" << endl;
					else cout << "Wrong Answer" << endl;
					delete(a); delete(b); delete(c);
				}
				if (i == 2)
				{
					cp_rectangle* a = new cp_rectangle(num);
					a->get_area(); a->get_length();
					cp_unit_test* b = new cp_unit_test(a->length, pari, 0.001);
					cp_unit_test* c = new cp_unit_test(a->area, area, 0.001);
					cout << "The output perimeter is " << a->length << ", the right answer is " << pari << endl;
					cout << "The output area is " << a->area << ", the right answer is " << area << endl;
					if (b->compare() && c->compare()) cout << "Right Answer" << endl;
					else cout << "Wrong Answer" << endl;
					delete(a); delete(b); delete(c);
				}
				if (i == 3)
				{
					cp_pantagon* a = new cp_pantagon(num);
					a->get_area(); a->get_length();
					cp_unit_test* b = new cp_unit_test(a->length, pari, 0.001);
					cp_unit_test* c = new cp_unit_test(a->area, area, 0.001);
					cout << "The output perimeter is " << a->length << ", the right answer is " << pari << endl;
					cout << "The output area is " << a->area << ", the right answer is " << area << endl;
					if (b->compare() && c->compare()) cout << "Right Answer" << endl;
					else cout << "Wrong Answer" << endl;
					delete(a); delete(b); delete(c);
				}
				if (i == 4)
				{
					cp_hexagon* a = new cp_hexagon(num);
					a->get_area(); a->get_length();
					cp_unit_test* b = new cp_unit_test(a->length, pari, 0.001);
					cp_unit_test* c = new cp_unit_test(a->area, area, 0.001);
					cout << "The output perimeter is " << a->length << ", the right answer is " << pari << endl;
					cout << "The output area is " << a->area << ", the right answer is " << area << endl;
					if (b->compare() && c->compare()) cout << "Right Answer" << endl;
					else cout << "Wrong Answer" << endl;
					delete(a); delete(b); delete(c);
				}
				if (i == 5)
				{
					cp_circle* a = new cp_circle(num);
					a->get_area(); a->get_length();
					cp_unit_test* b = new cp_unit_test(a->length, pari, 0.001);
					cp_unit_test* c = new cp_unit_test(a->area, area, 0.001);
					cout << "The output perimeter is " << a->length << ", the right answer is " << pari << endl;
					cout << "The output area is " << a->area << ", the right answer is " << area << endl;
					if (b->compare() && c->compare()) cout << "Right Answer" << endl;
					else cout << "Wrong Answer" << endl;
					delete(a); delete(b); delete(c);
				}
		}

	}



}