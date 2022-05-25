#include<iostream>
#include"cp_integer.h"
#include"cp_student.h"
#include"cp_chain_double_link.h"
#include"cp_student_system.h"
#include"cp_factoryinterface.h"
#include"cp_factory.h"
using namespace std;

cp_student* cp_factory::createinstance()
{
	cp_integer* c_code = NULL, *c_grade = NULL;
	c_code = new cp_integer();
	c_grade = new cp_integer();
	if (c_code == NULL || c_grade == NULL)
	{
		cout << "ERROR!" << endl;
		return NULL;
	}
	while (1)
	{
		cout << "Please input the ID of the student, input 0 to stop" << endl;
		c_code->integer_input();
		if (c_code->num < 0) cout << "Invalid input, please try again" << endl;
		else if (c_code->num == 0)
		{
			delete(c_code); delete(c_grade);
			return NULL;
		}
		else break;
	}
	while (1)
	{
		cout << "Please input the grade of the student" << endl;
		c_grade->integer_input();
		if (c_grade->num<0) cout << "Invalid input, please try again" << endl;
		else break;
	}
	cp_chain_double_link* s1 = NULL;
	if (head != NULL)
	{
		s1 = head->find_node(c_code->num, c_grade->num, 4);
	}
	cp_student* s = new cp_student();
	s->set(c_code->num, c_grade->num);
	if (s1 != NULL)
	{
		head->delete_node(s1);
	}
	delete(c_code); delete(c_grade);
	return s;
}

void cp_factory::restoreinstance(cp_student* stu)
{
	if (head == NULL)
	{
		head = new cp_chain_double_link();
	}
	head=head->add_node(*stu);
	delete(stu);
}
