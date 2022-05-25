#include<iostream>
#include<fstream>
#include"cp_longint.h"
#include"test.h"
using namespace std;
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void cp_longint::outputvalue_file()
{
	if (sign == 1) out << '+';
	if (sign == -1) out << '-';
	out << number << endl;
}
void test()
{
	int n;
	in >> n;
	int i;
	for (i = 1; i <= n; i++)
	{
		char cha[30], chb[30];
		in >> cha >> chb;
		cp_longint a_i, b_i,plus_i,minus_i,multi_i;
		string stra(cha), strb(chb);
		a_i.setvalue(stra);
		b_i.setvalue(strb);
		plus_i = a_i + b_i; minus_i = a_i - b_i; multi_i = a_i * b_i;
		out << "Set " << i << endl;
		out << "My answer:" << endl;
		out << "a="; a_i.outputvalue_file();
		out << "b="; b_i.outputvalue_file();
		out << "a+b="; plus_i.outputvalue_file();
		out << "a-b="; minus_i.outputvalue_file();
		out << "a*b="; multi_i.outputvalue_file();
		out << "Right answer:" << endl;
	}




}