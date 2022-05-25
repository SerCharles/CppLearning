#include<iostream>
#include<cmath>
#include"calendar.h"
void year_date::reset_date()
    {
       total_days=366;
       day_number[2]=29;
    }
    void year_date::get_date(int n)
    {
     switch_to_num();
     todays_num+=n;
     while(1)
     {
         if(todays_num>total_days)
         {
             todays_num-=total_days;
             if(year==-1) year=1;
             else year++;
             if(judge_type(year)==0) reset_date();
         }
         else if(todays_num<=0)
         {
             if(year==1) year=-1;
             else year--;
             if(judge_type(year)==0) reset_date();
             todays_num+=total_days;
         }
         else break;
     }
     switch_to_date();
    }
    void year_date::switch_to_num()
    {
        int i;
        todays_num=0;
        for(i=1;i<month;i++) todays_num+=day_number[i];
        
        todays_num+=day;
    }
    void year_date::switch_to_date()
    {
        int i=1,a=todays_num;
        month=1;
        while(a>day_number[month])
        {
         a-=day_number[month];
         month++;
        }
        day=a;
    }
int judge_type(int n)
{
 if(n>0)
 {
   if((n%4==0&&n%100!=0)||(n%400==0)) return 0;
   else return 1;
 }
 else
 {
     if(((0-n)%4==1&&(0-n)%100==1)||(0-n)%400==1) return 0;
     else return 1;
 }
}