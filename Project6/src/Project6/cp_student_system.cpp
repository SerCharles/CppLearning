#include<iostream>
#include"cp_integer.h"
#include"cp_student.h"
#include"cp_chain_double_link.h"
#include"cp_student_system.h"
using namespace std;
#define max 500000000
void cp_student_system::show_menu()
{
	cout << "Main Menu" << endl;
	cout << "1: Add students" << endl;
	cout << "2: Delete the first student with certain ID" << endl;
	cout << "3: Delete all students with certain grades" << endl;
	cout << "4: Show the grade of the first student with certain ID" << endl;
	cout << "5: Show the IDs of all students with certain grades" << endl;
	cout << "6: Show all the Students" << endl;
	cout << "-1: Quit" << endl;
}
void cp_student_system::add_students()
{
	
	while (1)
	{
		cp_integer* c_code = NULL, *c_grade = NULL;
		c_code = new cp_integer();
		c_grade = new cp_integer();
		if (c_code == NULL || c_grade == NULL)
		{
			cout << "ERROR!" << endl;
			return;
		}
		while (1)
		{
			cout << "Please input the ID of the student, input 0 to stop" << endl;
			c_code->integer_input();
			if (c_code->num < 0) cout << "Invalid input, please try again" << endl;
			else if (c_code->num == 0)
			{
				delete(c_code); delete(c_grade);
				return;
			}
			else break;
		}
		while (1)
		{
			cout << "Please input the grade of the student" << endl;
			c_grade->integer_input();
			if(c_grade->num<0) cout << "Invalid input, please try again" << endl;
			else break;
		}
		cp_student a;
		a.set(c_code->num, c_grade->num);
		head->add_node(a);
		delete(c_code); delete(c_grade);
	}
}
void cp_student_system::mb_run()
{
	show_menu();
	head = new cp_chain_double_link();
	while (1)
	{
		cp_integer* a = NULL;
		a = new cp_integer();
		if (a == NULL)
		{
			cout << "ERROR!" << endl;
			return;
		}
		cout << "Please input an instruction" << endl;
		while (1)
		{
			a->integer_input();
			if (a->num < -1 || a->num>6||a->num==0) cout << "Invalid input,please try again" << endl;
			else break;
		}
		if(a->num==-1)
		{
			delete(a);
			cout << "Quiting the program..." << endl;
			for (int tt = 1; tt <= max; tt++);
			return;
		}
		else if(a->num==1)
		{
			if (head == NULL)
			{
				head = new cp_chain_double_link();
			}
			if (head == NULL) break;
			add_students();
		}
		else if(a->num==2)
		{
			if (head == NULL) break;
			cp_integer* aa = NULL;
			cp_chain_double_link* t = NULL;
			aa = new cp_integer();
			if (aa == NULL)
			{
				cout << "ERROR!" << endl;
				return;
			}
			cout << "Please input the ID you want to know" << endl;
			aa->integer_input();
			t=head->find_node(aa->num,0,1);
			delete(aa);
			if (t == NULL) continue;
			else head->delete_node(t);
			t = NULL;
		}
		else if(a->num==3)
		{
			if (head == NULL) break;
			cp_integer* aa = NULL;
			cp_chain_double_link* t = NULL;
			aa = new cp_integer();
			if (aa == NULL)
			{
				cout << "ERROR!" << endl;
				return;
			}
			cout << "Please input the grade you want to know" << endl;
			aa->integer_input();
			while (1)
			{
				t = head->find_node(0, aa->num, 2);
				if (t == NULL) break;
				else head->delete_node(t);
			}
			delete(aa); t = NULL;
		}
		else if(a->num==4)
		{
			if (head == NULL)
			{
				cout << "No students you want yet" << endl;
				break;
			}
			cp_integer* aa = NULL;
			cp_chain_double_link* t = NULL;
			aa = new cp_integer();
			if (aa == NULL)
			{
				cout << "ERROR!" << endl;
				return;
			}
			cout << "Please input the ID you want to know" << endl;
			aa->integer_input();
			t = head->find_node(aa->num, 0, 1);
			delete(aa);
			if (t == NULL)
			{
				cout << "No students you want yet" << endl;
			}
			else head->print_node(t,2);
			t = NULL;
		}
		else if(a->num==5)
		{
			if (head == NULL)
			{
				cout << "No students you want yet" << endl;
				break;
			}
			cp_integer* aa = NULL;
			cp_chain_double_link* t = NULL;
			aa = new cp_integer();
			if (aa == NULL)
			{
				cout << "ERROR!" << endl;
				return;
			}
			cout << "Please input the grade you want to know" << endl;
			aa->integer_input();
			int whether = 0;
			while (1)
			{

				t = head->find_node(0, aa->num, 2);
				if (t == NULL&&whether==1)
				{
					cout << "All students you want is here" << endl;
					break;
				}
				else if (t == NULL && whether == 0)
				{
					cout << "No student you want yet" << endl;
					break;
				}
				else
				{
					head->print_node(t, 1);
					whether = 1;
				}
			}
			delete(aa); t = NULL;
		}
		else if(a->num==6)
		{
			int whether = 0;
			if (head == NULL)
			{
				cout << "No student" << endl;
				break;
			}
			cp_chain_double_link* t = NULL;
			while (1)
			{
				t = head->find_node(0, 0, 3);
				if (t == NULL&&whether==1)
				{
					cout << "All students you want is here" << endl;
					break;
				}
				else if (t == NULL && whether == 0)
				{
					cout << "No student" << endl;
					break;
				}
				else
				{
					head->print_node(t, 3);
					whether = 1;
				}
			}
			t = NULL;
		}
		if (head != NULL)
		{
			head->sort();
			head->reset_node();
		}
		}
}