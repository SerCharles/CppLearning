#include<iostream>
#include"cp_student.h"
void cp_student::set(int a, int b)
{
	code = a; grade = b;
}
void cp_student::get(int &a, int &b)
{
 a = code; b = grade;
}
int cp_student::compare_code(cp_student& b)
{
	int c_b, g_b;
	b.get(c_b, g_b);
	if (code > c_b) return 1;
	else if (code == c_b) return 0;
	else return -1;
}
void cp_student::swap(cp_student& b)
{
	int c_b, g_b,c_temp,g_temp;
	b.get(c_b, g_b);
	c_temp = code; g_temp = grade;
	code = c_b; grade = g_b;
	b.set(c_temp, g_temp);
}