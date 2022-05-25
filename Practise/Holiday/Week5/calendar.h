#ifndef CALENDAR_H
#define CALENDAR_H
extern int judge_type(int n);
class year_date
{
public:
 int year,month,day,total_days,todays_num;
 int day_number[13];
public:
year_date(){year=1;month=1;day=1;total_days=365;todays_num=1;
    day_number[1]=31;day_number[2]=28;day_number[3]=31;day_number[4]=30;day_number[5]=31;day_number[6]=30;
    day_number[7]=31;day_number[8]=31;day_number[9]=30;day_number[10]=31;day_number[11]=30;day_number[12]=31;}
~year_date(){}
public:
void get_date(int n);
void reset_date();
void switch_to_num();
void switch_to_date();
};

#endif