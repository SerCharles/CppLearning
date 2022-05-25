#include<iostream>
#include"cp_integer.h"
using namespace std;
#define MAX 1000000000
int main(int argc, char* argv[])
{
	cp_integer* a = NULL;
	try
	{
		a = new cp_integer();
		if (a == NULL) throw 0;
	}
	catch(int i)
	{
		if (i == 0)
		{
			cout << "Cannot new an object!";
			delete(a);
			return 0;
		}
	}
	a->input();
	a->output();
	a->input(1233);
	a->output();
	a->input(-4, 's');
	a->output();
	a->input(0, 300);
	a->output();
	a->input(100, 100);
	a->output();
	a->input(100, 99);
	a->output();
	delete(a);
	cout << "Waiting for the program to quit...";
	for (int i = 1; i <= MAX; i++);
	return 0;
}