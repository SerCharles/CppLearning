#include<iostream>
#include"cp_longint.h"
#include"test.h"
using namespace std;
int main(int argv, char* argc[])
{
	test();
	cp_longint a;
	cout << "Please input the number a" << endl;
	a.inputvalue();
	cout << "Now output a:" << endl;
	a.outputvalue();
	cp_longint b;
	cout << "Please input the number a" << endl;
	b.inputvalue();
	cout << "Now output b:" << endl;
	b.outputvalue();
	cp_longint result1,result2,result3;
	result1= a + b;
	cout << "Now output a+b:" << endl;
	result1.outputvalue();
	result2 = a - b;
	cout << "Now output a-b:" << endl;
	result2.outputvalue();
	result3 = a * b;
	cout << "Now output a*b:" << endl;
	result3.outputvalue();
	/*string temp("fiej-0-+++----39901837738183djejhdd+-du22");
	a->setvalue(temp);
	a->outputvalue();*/

	while (1);
	return 0;
}