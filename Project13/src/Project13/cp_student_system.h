#ifndef CP_STUDENT_SYSTEM_H
#define CP_STUDENT_SYSTEM_H
#include"cp_chain_double_link.h"
#include"cp_student.h"
class cp_student_system
{
public:
	cp_chain_double_link * head;
public:
	cp_student_system():head(NULL) {}
	~cp_student_system() { delete(head); }
	void working_section();
};
#endif