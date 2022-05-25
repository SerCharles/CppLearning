#ifndef CP_DATE_H
#define CP_DATE_H
class cp_date
{
private:
	int year, month, day;
	int day_per_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day_per_year;
	bool leapyear;
	void judge_leap_year();
public:
	cp_date() :year(1257), month(2), day(8),leapyear(0),day_per_year(365){}
	~cp_date(){}
	
public:
	void date_input();
	void date_set(int y,int m,int d);
	void date_output();
	void date_get(int n);
};
#endif
