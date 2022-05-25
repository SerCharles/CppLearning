#ifndef CP_TWO_INTEGERS_H
#define CP_TWO_INTEGERS_H
class cp_two_integers
{
public:
	int num1,num2;
	int  greatest_common_divisor;
	long long least_common_multiple;
public:
	cp_two_integers(int i=0,int j=0):num1(i),num2(j),least_common_multiple(0),greatest_common_divisor(0){}
	~cp_two_integers(){}
public:
	void get_gcd_and_lcm();
	void print();
	bool judge_gcd_and_lcm();
};
#endif