#include<iostream>
#include<fstream>
#include"cp_double_union.h"
#include"union_test.h"
using namespace std;
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void union_test()
{
	cp_double_union test;
	int n;
	in >> n;
	int i;
	for (i = 1; i <= n; i++)
	{
		double c;
		in >> c;
		test.num.decimal = c;
		out << "The " << i << " set" << endl;
		test.get_binary();
	}
}
void cp_double_union::get_binary()
{
	int i;
	bool binary[64];
	out << "The original double is " << num.decimal << endl;
	for (i = 1; i <= 64; i++)
	{
		bool temp = num.equal_decimal & 9223372036854775808;
		binary[i - 1] = temp;
		num.equal_decimal <<= 1;
	}
	num.equal_decimal = 0;
	regain_double(binary);
	out << "The binary is ";
	for (i = 0; i < 64; i++)
	{
		out << binary[i];
	}
	out << "\n";
	out << "The new double is ";
	out << num.decimal << endl;
	out << "-----------------------------------------------------------------------" << endl;
}
void cp_double_union::regain_double(bool binary[])
{
	num.equal_decimal = 0;
	int i;
	for (i = 0; i <63 ; i++)
	{
		num.equal_decimal += (binary[i] - '0');
		num.equal_decimal <<= 1;
	}
	num.equal_decimal += (binary[63] - '0');
}