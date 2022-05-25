#include<iostream>
#include<cmath>
#include"cp_date.h"
using namespace std;
int switch_to_day(int month, int day, int day_per_month[]);
void judge_leap_year_new(int year, int* feb, int* day_per_year);
void switch_to_month(int num, int* month, int* day, int day_per_month[]);
void cp_date::date_get(int n)
{
	int day_per_month_new[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year_new = year, month_new = month, day_new = day, day_per_year_new = 365;
	long long num = 0;
	if (leapyear)
	{
		day_per_month_new[2] = 29;
		day_per_year_new = 366;
	}
	num = long long(switch_to_day(month_new, day_new, day_per_month_new));
	if (n >= 0)
	{
		num += long long(n);
		while (num > day_per_year_new)
		{
			num -= day_per_year_new;
			if (year_new != -1) year_new++;
			else year_new = 1;
			judge_leap_year_new(year_new, &day_per_month_new[2], &day_per_year_new);
		}
	}
	else
	{
		num += long long(n);
		while (num <= 0)
		{
			if (year_new != 1)
			{
				judge_leap_year_new(year_new - 1, &day_per_month_new[2], &day_per_year_new);
			}
			else
			{
				judge_leap_year_new(year_new - 2, &day_per_month_new[2], &day_per_year_new);
			}
			num += day_per_year_new;
			if (year_new != 1) year_new--;
			else year_new = -1;
		}
	}
	switch_to_month(num, &month_new, &day_new,day_per_month_new);
	if (year_new > 0)	cout << "The date you want is " << month_new << "/" << day_new << "/" << year_new << " AD." << endl;
	else cout<<"The date you want is " << month_new << "/" << day_new << "/" << 0-year_new << " BC." << endl;
}
int switch_to_day(int month, int day, int day_per_month[])
{
	int i,num=0;
	for (i = 1; i < month; i++) num += day_per_month[i];
	num += day;
	return num;
}
void judge_leap_year_new(int year,int* feb,int* day_per_year)
{
	int y;
	if (year > 0) y = year;
	else y = 0 - year - 1;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		*feb= 29;
		*day_per_year = 366;
	}
	else
	{
		*feb = 28;
		*day_per_year = 365;
	}
}
void switch_to_month(int num, int* month, int* day, int day_per_month[])
{
	*month = 1; *day = 0;
	int i = 1;
	while (num > day_per_month[i])
	{
		num -= day_per_month[i];
		i++;
	}
	*month = i;
	*day = num;
}