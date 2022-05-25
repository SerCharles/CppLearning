#ifndef CP_ARRAY_H
#define CP_ARRAY_H
#include<vector>
#include<set>
using namespace std;
class cp_array
{
public:
	int num;
	vector<int> array;
	set<int> array_set;
	cp_array(int i) :num(i){}
	~cp_array() { array.clear(); array_set.clear(); }
	void input();
	void output_vector();
	void output_set();
	void sort_array();
	void output_file_vector();
	void output_file_set();
};
#endif