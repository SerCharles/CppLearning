#ifndef CP_STUDENT_H
#define CP_STUDENT_H
class cp_student
{
private:
	int code, grade;
public:
	cp_student():code(0),grade(0){}
	~cp_student(){}
	void set(int a, int b);
	void get(int &a, int &b);
	int compare_code(cp_student &b);//>���1��=���0��<���-1
	void swap(cp_student &b);
};
#endif
