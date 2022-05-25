#ifndef CP_TIME_BY_CLOCK_H
#define CP_TIME_BY_CLOCK_H
#include<ctime>
class cp_time_by_clock
{
private:
	clock_t m_time_start, m_time_end;
public:
	cp_time_by_clock() {}
	~cp_time_by_clock(){}
public:
	void get_time_start();
	void get_time_end();
	void get_time_total();
};
#endif // !CP_TIME_BY_CLOCK_H
