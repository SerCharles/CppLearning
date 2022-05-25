#ifndef CP_CHAIN_DOUBLE_LINK_H
#define CP_CHAIN_DOUBLE_LINK_H
#include"cp_student.h"
#include<iostream>
class cp_chain_double_link
{
public:
	cp_chain_double_link * last;
	cp_chain_double_link* next;
	bool visit;
	cp_student student;
public:
	cp_chain_double_link() :last(NULL), next(NULL),visit(0) {}
	~cp_chain_double_link();
	cp_chain_double_link* add_node(cp_student &a);
	cp_student* delete_node(cp_chain_double_link* &p);
	cp_chain_double_link* find_node(int id,int grade,int type); //1:id,2:type,3:all
	void print_node(cp_chain_double_link* &p,int i);//1--code,2--grade,3--all
	void reset_node();
	void sort();
};
#endif
