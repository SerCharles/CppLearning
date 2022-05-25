#include<string>
#ifndef CP_LONGINT_H
#define CP_LONGINT_H
using namespace std;
class cp_longint
{
private: 
	string number;
	int sign; //-1 minus,1 plus
public:
	cp_longint():sign(0),number("0"){}
	~cp_longint(){}
	void setvalue(string &a);
	void inputvalue();
	void outputvalue();
	void outputvalue_file();
	friend cp_longint operator + (cp_longint a, cp_longint b);
	friend cp_longint operator - (cp_longint a, cp_longint b);
	friend cp_longint operator * (cp_longint a, cp_longint b);
};
extern cp_longint operator + (cp_longint a, cp_longint b);
extern cp_longint operator - (cp_longint a, cp_longint b);
extern cp_longint operator * (cp_longint a, cp_longint b);





#endif
