#include<iostream>
#include"cp_student.h"
#include"cp_chain_double_link.h"
using namespace std;
cp_chain_double_link::~cp_chain_double_link()
{
	if (last == NULL) return;
	last->next = NULL; //断掉环
	delete(next); //递归删除
}
cp_chain_double_link* cp_chain_double_link::add_node(cp_student& a)
{
	int c_code, c_grade;
	a.get(c_code, c_grade);
	if (last == NULL) //0个
	{
		last =this;
		next =this;
		student.set(c_code, c_grade);
		return this;	
	}
	else        //多个
	{
		cp_chain_double_link* nova = NULL;
		nova = new cp_chain_double_link();
		if (nova == NULL) return NULL;
		nova->student.set(c_code, c_grade);
		this->last->next = nova;
		nova->last = this->last;
		nova->next = this;
		this->last = nova;
		return nova;
	}
}
cp_chain_double_link* cp_chain_double_link::find_node(int id,int grade,int type)
{
	int c_code, c_grade;
	if (last == NULL) return NULL; //0个
	this->student.get(c_code, c_grade);
	if (this->last == this) //1个
	{
			if (this->visit == 0)
			{
				if (type == 1 && c_code == id)
				{
					this->visit = 1;
					return this;
				}
				if (type == 2 && c_grade == grade)
				{
						this->visit = 1;
						return this;
				}
				if (type == 3)
				{
					this->visit = 1;
					return this;
				}
			}
			else return NULL;
	}
	//多个
	cp_chain_double_link* flag = this->next;
	if (this->visit==0)
	{
			if (type == 1 && c_code == id)
			{
				this->visit = 1;
				return this;
			}
			if (type == 2 && c_grade == grade)
			{
				this->visit = 1;
				return this;
			}
			if (type == 3)
			{
				this->visit = 1;
				return this;
			}
	}
	while (flag != this)
	{
		int f_code, f_grade;
		flag->student.get(f_code, f_grade);
		if (flag->visit == 0)
		{
			if (type == 1 && f_code == id)
			{
				flag->visit = 1;
				return flag;
			}
			if (type == 2 && f_grade == grade)
			{
				flag->visit = 1;
				return flag;
			}
			if (type == 3)
			{
				flag->visit = 1;
				return flag;
			}
		}
		flag = flag->next;
	}
	return NULL;
}
void cp_chain_double_link::delete_node(cp_chain_double_link* &p)
{
	if (p == NULL) return; //0
	if (p->last == p) //1
	{
		p->last = NULL;
		return;
	}
	//>1
	if (this == p)
	{
		student.swap(this->next->student);
		bool temp;
		temp = this->visit;
		this->visit = this->next->visit;
		this->next->visit = temp;
		p = p->next;
	}
	p->last->next = p->next;
	p->next->last = p->last;
	p->last = NULL;
	p->next = NULL;
	delete(p);
}
void cp_chain_double_link::print_node(cp_chain_double_link* &p, int i)
{
	int c_code, c_grade;
	if (p == NULL)
	{
		cout << "No Students yet" << endl;
		return;
	}
	p->student.get(c_code, c_grade);
	if (i == 1)
	{
		cout << "The ID of the student is " << c_code << endl;
	}
	else if (i == 2)
	{
		cout << "The grade of the student is " << c_grade << endl;
	}
	else
	{
		cout << "The ID of the student is " << c_code << ", and the grade of the student is " << c_grade << endl;
	}
}
void cp_chain_double_link::reset_node()
{
	if (this->last == NULL) return;//0
	if (this->last == this) //1
	{
		this->visit = 0;
		return;
	}
	cp_chain_double_link* flag = this->next;
	this->visit = 0;
	while (flag != this)
	{
		flag->visit = 0;
		flag = flag->next;
	}
}
void cp_chain_double_link::sort()
{
	if (this->last == this||this->last==NULL) return;//0or1
	cp_chain_double_link* flag_h = this, *flag_t = this->next;
	while (flag_h != this->last)
	{
		flag_t = flag_h->next;
		while (flag_t != this)
		{
			int t = flag_h->student.compare_code(flag_t->student);
			if (t == 1) flag_h->student.swap(flag_t->student);
			flag_t = flag_t->next;
		}
		flag_h = flag_h->next;
	}
}