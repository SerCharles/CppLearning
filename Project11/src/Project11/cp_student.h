#ifndef CP_STUDENT
#define CP_STUDENT
#include<vector>
using namespace std;
class cp_student
{
private:
	string code;
	int score;
public:
	cp_student():score(0){}
	~cp_student(){}
	void set(string s, int num);
	bool match(string s);
	void show();
	void get(string &s, int &num);
	//void show(string s);
};
#endif