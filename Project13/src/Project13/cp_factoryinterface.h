#ifndef CP_FACTORYINTERFACE_H
#define CP_FACTORYINTERFACE_H

class cp_factoryinterface :public cp_student_system
{
public:
	virtual ~cp_factoryinterface(){}
	virtual cp_student* createinstance()=0;

};
#endif
