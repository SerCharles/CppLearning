#include<iostream>
#include<cmath>
#include"cp_date.h"
#include"cp_integer.h"
using namespace std;
void cp_date::judge_leap_year()
{
	int y;
	if (year > 0) y = year;
	else y = 0 - year - 1;
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		{
			leapyear = 1;
			day_per_month[2] = 29;
			day_per_year = 366;
		}
		else
		{
			leapyear = 0;
			day_per_month[2] = 28;
			day_per_year = 365;
		}
}
void cp_date::date_set(int y, int m, int d)
{
	year = y;
	month=m;
	day=d;
}
void cp_date::date_input()
{
	cp_integer* year_input = new cp_integer();
	cp_integer* month_input = new cp_integer();
	cp_integer* day_input = new cp_integer();
	while (1)
	{
		cout << "Please input the year" << endl;
		year_input->integer_input();
		if (year_input->num == 0)
		{
			cout << "Invalid input, please try again." << endl;
		}
		else break;
	}
	year = year_input->num;
	judge_leap_year();
	while (1)
	{
		cout << "Please input the month" << endl;
		month_input->integer_input();
		if (month_input->num <= 0 || month_input->num > 12)
		{
			cout << "Invalid input, please try again." << endl;
		}
		else break;
	}
	month = month_input->num;
	while (1)
	{
		cout << "Please input the day" << endl;
		day_input->integer_input();
		if (day_input->num <= 0 || day_input->num > day_per_month[month])
		{
			cout << "Invalid input, please try again." << endl;
		}
		else break;
	}
	day = day_input->num;
	delete(year_input); delete(month_input); delete(day_input);
}
void cp_date::date_output()
{
	    cout << "The date is ";
		if (year < 0) cout <<month<<"/"<<day<<"/"<< 0 - year << " BC." << endl;
		else cout << month << "/" << day << "/" << year << " AD." << endl;
}
