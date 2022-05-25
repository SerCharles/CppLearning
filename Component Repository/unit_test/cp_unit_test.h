#ifndef CP_UNIT_TEST_H
#define CP_UNIT_TEST_H

class cp_unit_test
{
public:
	double result, right_answer, difference;
public:
	cp_unit_test(double a,double b,double c):result(a),right_answer(b),difference(c){}
	~cp_unit_test(){}
public:
	int compare();
};
#endif
