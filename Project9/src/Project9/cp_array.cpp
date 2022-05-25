#include<iostream>
#include<vector>
#include<algorithm>
#include"cp_array.h"
#include"cp_integer.h"
using namespace std;
void cp_array::input()
{
	int i;
	cout << "Now Please input the integers one by one." << endl;
	for (i = 1; i <= num; i++) 
	{
		cout << "Please input the " << i << "th integer." << endl;
			cp_integer* t = NULL;
			t = new cp_integer();
			if (t == NULL) return;
			t->integer_input();
			array.push_back(t->num);
			array_set.insert(t->num);
			delete(t);
	}
}
void cp_array::output_vector()
{
	vector<int>::iterator a = array.begin();
for (a; a != array.end(); a++)
	{
		cout << *a << " ";
	}
	cout << endl;
}
void cp_array::output_set()
{
	set<int>::iterator a = array_set.begin();
	for (a; a != array_set.end(); a++)
	{
		cout << *a << " ";
	}
	cout << endl;
}
void cp_array::sort_array()
{
	sort(array.begin(), array.end());
	//sort(array_set.begin(), array_set.end());
}
