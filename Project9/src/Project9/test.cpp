#include<iostream>
#include<fstream>
#include"test.h"
#include"cp_integer.h"
#include"cp_array.h"
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define numbers 23
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void cp_array::output_file_vector()
{
	vector<int>::iterator a = array.begin();
	for (a; a != array.end(); a++)
	{
		out << *a << " ";
	}
	out << endl;
}
void cp_array::output_file_set()
{
	set<int>::iterator a = array_set.begin();
	for (a; a != array_set.end(); a++)
	{
		out << *a << " ";
	}
	out << endl;
}
void test()
{
	for (int i = 1; i <= numbers; i++)
	{
		int n;
		in >> n;
		cp_array* a=NULL;
		a = new cp_array(n);
		if (a == NULL) return;
		for (int j = 1; j <= n; j++)
		{
			int temp;
			in >> temp;
			a->array.push_back(temp);
			a->array_set.insert(temp);
		}
		out << "Set " << i << endl;
		out << "The original set :" << endl;
		a->output_file_vector();
		a->sort_array();
		out << "The sorted set with repeatition:" << endl;
		a->output_file_vector();
		out << "The sorted set without repeatition:" << endl;
		a->output_file_set();
		delete(a);
	}
}