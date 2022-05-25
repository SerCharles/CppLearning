#include<iostream>
#include"cp_array.h"
#include"cp_integer.h"
#include"test.h"
using namespace std;
int main(int argv,char* argc[])
{
	test();
	cp_integer* n = NULL;
	n = new cp_integer();
	if (n == NULL) return 0;
	while (1)
	{
		cout << "Please input a positive integer as the number of the integers in the set." << endl;
		n->integer_input();
		if (n->num > 0) break;
		else cout << "Invalid input,please input again" << endl;
	}
	cp_array* a=NULL;
	a = new cp_array(n->num);
	if (a == NULL) return 0;
	delete(n);
	a->input();
	cout << "The original set :" << endl;
	a->output_vector();
	a->sort_array();
	cout << "The sorted set with repeatition:" << endl;
	a->output_vector();
	cout << "The sorted set without repeatition:" << endl;
	a->output_set();
	delete(a);
	while (1);
	return 0;
}