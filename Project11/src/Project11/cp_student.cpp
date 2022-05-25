#include<iostream>
#include<vector>
#include<fstream>
#include"cp_student.h"
using namespace std;
void cp_student::set(string s, int num)
{
	code = s;
	score = num;
}
bool cp_student::match(string s)
{
	if (s.compare(code)==0)
	{
		return 1;
	}
	else return 0;
}
void cp_student::show()
{
	cout << "Code=";
	int i;
	for (i = 0; i < code.size(); i++) cout << code[i];
	cout<< ", score=" << score << endl;
}
/*void cp_student::show(string s)
{
	fstream out(s,ios_base::in|ios_base::out);
	out.seekp(ios_base::end);
	out << "\n";
	for (int i = 0; i < code.size(); i++) out << code[i];
	out << " " << score;
}*/
void cp_student::get(string &s, int &num)
{
	s = code;
	num = score;
}