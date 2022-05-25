#include<iostream>
#include<cmath>
#include"cp_unit_test.h"
using namespace std;
int cp_unit_test::compare()
{
	double a = abs(result - right_answer);
	double b = abs(a / right_answer);
	if (b <= difference) return 1;
	else return 0;
}