#include<iostream>
#include<vector>
#include"cp_student.h"
#include"cp_student_list.h"
#include"cp_integer.h"
#include<fstream>
using namespace std;
void cp_student_list::main_control()
{
	while (1)
	{
		cout << "1: add a list from file" << endl;
		cout << "2: add a student" << endl;
		cout << "3: delete a student" << endl;
		cout << "4: delete the list" << endl;
		cout << "5: change a student" << endl;
		cout << "6: show a student" << endl;
		cout << "7: show the list" << endl;
		cout << "8: save the file" << endl;
		cout << "-1: quit program" << endl;
		cout << "Please input an integer of -1 or from 1 to 8 as an instruction" << endl;
		cp_integer a;
		while (1)
		{
			a.integer_input();
			if (a.num < -1 || a.num>8 || a.num == 0) cout << "Invalid input, please try again" << endl;
			else break;
		}
		if (a.num == -1) break;
		if (a.num == 1) open_file();
		if (a.num == 2) add_one();
		if (a.num == 3) delete_one();
		if (a.num == 4) clear();
		if (a.num == 5) change_one();
		if (a.num == 6) show_one();
		if (a.num == 7) show();
		if (a.num == 8) save();
	}
}
int cp_student_list::search(string s)
{
	int i;
	for (i = 0; i < list.size(); i++)
	{
		if (list[i].match(s)) return i;
	}
	return -1;
}
void cp_student_list::add_one()
{
	cp_student* student = NULL;
	student = new cp_student();
	if (student == NULL) return;
	char a[1000];
	cout << "Please input a char as the code"<< endl;
	cin >> a;
	string aa(a);
	if (search(aa) != -1)
	{
		cout << "One student with the code has existed!" << endl;
		return;
	}
	cout << "Please input an integer from 0 to 100 as the grade" << endl;
	cp_integer* b = NULL;
	b = new cp_integer();
	if (b == NULL) return;
	while (1)
	{
		b->integer_input();
		if (b->num < 0 || b->num>100)
		{
			cout << "Invalid input,please try again" << endl;
		}
		else break;
	}
	student->set(aa, b->num);
	list.push_back(*student);
	delete(student); delete(b);
}
void cp_student_list::change_one()
{
	char a[1000];
	cout << "Please input a char as the code" << endl;
	cin >> a;
	string aa(a);
	cout << "Please input an integer from 0 to 100 as the grade" << endl;
	cp_integer* b = NULL;
	b = new cp_integer();
	if (b == NULL) return;
	while (1)
	{
		b->integer_input();
		if (b->num < 0 || b->num>100)
		{
			cout << "Invalid input,please try again" << endl;
		}
		else break;
	}
	int i = search(aa);
	if (i == -1)
	{
		cout << "No such student exists!" << endl;
		return;
	}
	list[i].set(aa, b->num);
    delete(b);
}
void cp_student_list::delete_one()
{
	char a[1000];
	cout << "Please input a char as the code" << endl;
	cin >> a;
	string aa(a);
	int i = search(aa);
	if (i == -1)
	{
		cout << "No such student exists!" << endl;
		return;
	}
	vector<cp_student>::iterator j;
	j = list.begin();
	j += i;
	list.erase(j);
}
void cp_student_list::show_one()
{
	char a[1000];
	cout << "Please input a char as the code" << endl;
	cin >> a;
	string aa(a);
	int i = search(aa);
	if (i == -1)
	{
		cout << "No such student exists!" << endl;
		return;
	}
	list[i].show();
}
void cp_student_list::show()
{
	int i;
	if (list.size() == 0) cout << "Empty list!" << endl;
	for (i = 0; i < list.size(); i++) list[i].show();
}
void cp_student_list::clear()
{
	list.clear();
}
void cp_student_list::open_file()
{
	char c[1000],p[1000];
	int n,i;
	cout << "Please input the name of file" << endl;
	cin >> c;
	ifstream in(c);
	in >> n;
	for (i = 1; i <= n; i++)
	{
		in >> p;
		int m;
		in >> m;
		string aa(p);
		if (search(aa) == -1)
		{
			cp_student nova;
			nova.set(aa, m);
			list.push_back(nova);
		}
	}
}
void cp_student_list::save()
{
	fstream out("list.txt",  ios_base::in | ios_base::out|ios_base::trunc);
	int i;
	string s("list.txt");
	out << list.size() << endl;
	for (i = 0; i < list.size(); i++)
	{
		string cd;
		int nm;
		list[i].get(cd, nm);
		int j;
		for (j = 0; j < cd.size(); j++) out << cd[j];
		out << " " << nm<<endl;
	}
}