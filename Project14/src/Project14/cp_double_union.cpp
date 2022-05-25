/*
* cp_double_union.cpp
*
* 
* 主界面，读入double，输出一个double的二进制
*
* Charles Shen
*
* 1.0.0 6/5/2018
*/
#include<iostream>
#include"cp_double_union.h"
#include"cp_integer.h"
#define MAX 1000000000
using namespace std;

void cp_double_union::main_section()
{
	while (1)
	{
		cout << "Please input an integer as the mode" << endl;
		cout << "Input 1 to get the binary number of an ordinary double" << endl;
		cout << "Input 2 to get the binary number of 0/0" << endl;
		cout << "Input 3 to get the binary number of positive infinity" << endl;
		cout << "Input 4 to get the binary number of negative infinity" << endl;
		cout << "Input 0 to quit" << endl;
		cp_integer aa;
		int mode;
		aa.input(0, 4);
		mode = aa.get();
		if (mode == 0)
		{
			cout << "Quiting the program......" << endl;
			for (int i = 1; i <= MAX; i++);
			break;
		}
		else if (mode == 1)
		{
			bool a=input_double();
			if (a != 0) get_binary(1);
		}
		else if (mode == 2)
		{
			double a = 0, b = 0;
			num.decimal = a / b;
			get_binary(2);
		}
		else if (mode == 3)
		{
			double a = 1, b = 0;
			num.decimal = a / b;
			get_binary(3);
		}
		else if (mode == 4)
		{
			double a = 0-1, b = 0;
			num.decimal = a / b;
			get_binary(4);
		}
		cin.clear();
	}
}
bool cp_double_union::input_double()
{
	cout << "Please input a double" << endl;
	cin.clear();
	cin >> num.decimal;
	if (cin.good())
	{
		return 1;
	}
	else
	{
		cout << "ERROR:Invalid input!" << endl;
		return 0;
	}
}
void cp_double_union::get_binary(int mode)
{
	int i;
	if (mode == 1) cout << "The binary of the double is ";
	else if (mode == 2) cout << "The binary of 0/0 is ";
	else if (mode == 3) cout << "The binary of positive infinity is ";
	else if (mode == 4) cout << "The binary of negative infinity is ";
	bool binary[64];
	int sum = 0;
	for (i = 1; i <= 64; i++)
	{
		bool temp = num.equal_decimal & 9223372036854775808;
		cout << temp;
		num.equal_decimal <<= 1;
	}
	num.equal_decimal = 0;
	cout << "\n";
}
