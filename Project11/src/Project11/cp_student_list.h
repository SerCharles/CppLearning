#ifndef CP_STUDENT_LIST_H
#define CP_STUDENT_LIST_H
#include"cp_student.h"
class cp_student_list
{
public:
	vector<cp_student>list;
	cp_student_list(){}
	~cp_student_list(){}
	int search(string s);
	void main_control();
	void open_file();
	void add_one();
	void delete_one();
	void clear();
	void change_one();
	void show_one();
	void show();
	void save();
};









#endif
