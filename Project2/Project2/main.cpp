#include<iostream>
using namespace std;
#include "cp_integer.h"
#include "cp_two_integers.h"
#include "integer_random_render.h"
#include"cp_time_by_clock.h"
int judge()
{
	int a, b,i;
	for (i = 1; i <= 10000; i++)
	{
		a = integer_random_render(1, 140226);
		b = integer_random_render(1, 140226);
		cp_two_integers* dual = new cp_two_integers(a, b);
		dual->get_gcd_and_lcm();
		if (dual->judge_gcd_and_lcm() == 0) return 0;
	}
	return 1;
}
int main(int argv, char* argc[])
{
	cp_integer* a = new cp_integer();
	cp_integer* b = new cp_integer();
	cout << "Now input the first integer" << endl;
	while (1)
	{
		a->integer_input();
		if (a->num>0) break;
		else
		{
			cout << "Invalid input, please try again." << endl;
		}
	}
	cout << "Now input the second integer" << endl;
	while (1)
	{
		b->integer_input();
		if (b->num>0) break;
		else
		{
			cout << "Invalid input, please try again." << endl;
		}
	}
	cp_time_by_clock* t = new cp_time_by_clock();
	t->get_time_start();
	cp_two_integers* dual = new cp_two_integers(a->num, b->num);//new 相当于调用构造函数
	delete(a); delete(b);
	dual->get_gcd_and_lcm();
	dual->print();
	delete(dual);
	if (judge())
	{
		cout << "These GCDs and LCMs are all right." << endl;
	}
	else
	{
		cout << "At least one of these GCDs or LCMs is wrong." << endl;
	}
	t->get_time_end();
	t->get_time_total();
	delete(t);
	while (1);
	return 0;
}
