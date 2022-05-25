#include<iostream>
#include"cp_integer.h"
#include"cp_student.h"
#include"cp_chain_double_link.h"
#include"cp_student_system.h"
#include"cp_factoryinterface.h"
#include"cp_factory.h"
#include"working_section.h"
using namespace std;
cp_student* addinstance(cp_factory* t)
{
	cp_student* s = t->createinstance();
	return s;
}
void reinstance(cp_student* stu,cp_factory* t)
{
	t->restoreinstance(stu);
}
