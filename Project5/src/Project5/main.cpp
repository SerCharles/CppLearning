#include <iostream>
#include"cp_complex.h"
#include"test.h"
#include"cp_integer.h"
using namespace std;
int main(int argv, char* argc[])
{
	cp_integer* a1 = new cp_integer();
	cp_integer* a2 = new cp_integer();
	cp_integer* b1 = new cp_integer();
	cp_integer* b2 = new cp_integer();
	cout << "Please input the real number of a" << endl;
	a1->integer_input();
	cout << "Please input the imaginary number of a" << endl;
	a2->integer_input();
	cout << "Please input the real number of b" << endl;
	b1->integer_input();
	cout << "Please input the imaginary number of a" << endl;
	b2->integer_input();
	cp_complex a, b;
	a.set_value(a1->num, a2->num);
	b.set_value(b1->num, b2->num);
	delete(a1); delete(a2); delete(b1); delete(b2);
	cp_complex plus, minus, multi, divide;
	plus = a + b; minus = a - b; multi = a * b; divide = a / b;
	char aa[] = "a", bb[] = "b", cc[] = "a + b", dd[] = "a - b", ee[] = "a * b", ff[] = "a / b";
	a.output_windows(aa);
	b.output_windows(bb);
	plus.output_windows(cc);
	minus.output_windows(dd);
	multi.output_windows(ee);
	double t1, t2;
	b.get_value(&t1, &t2);
	if (t1 == 0 && t2 == 0)
	{
		cout << "Cannot do the division!" << endl;
	}
	else
	{
		divide.output_windows(ff);
	}
	test();
	while (1);
	return 0;
}