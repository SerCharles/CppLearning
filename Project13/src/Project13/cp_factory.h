#ifndef CP_FACTORY_H
#define CP_FACTORY_H

class cp_factory :public cp_factoryinterface
{
public:
	virtual cp_student* createinstance();
	virtual void restoreinstance(cp_student* stu);
};
extern cp_student* addinstance(cp_factory* t);
extern void reinstance(cp_student* stu, cp_factory* t);
#endif