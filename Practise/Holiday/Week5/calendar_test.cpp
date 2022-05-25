#include<iostream>
#include<cmath>
using namespace std;
#include"calendar.h"
#include"calendar_test.h"
int main(int argc, char* argv[])
{
  year_date* today=new year_date();
  today->year=input_year();
  if(judge_type(today->year)==0)
  {
      today->reset_date();
  }
  today->month=input_month();
  today->day=input_day(today);
  int n=input_number();
  today->get_date(n);
  cout<<"The day you ask is "<<today->month<<"/"<<today->day<<"/"<<today->year<<endl;
  return 0;
}
int input_year()
{
    int y=0;
  while(1)
  {
   cout<<"Please input an integer as this year"<<endl;
   cin>>y;
   if(cin.good()&&y!=0) return y;
   else
   {
       cout<<"Invalid input"<<endl;
       cin.clear( ); // 来清除错误状态
       cin.sync( ); // 换行
   }
  }
}
int  input_month()
{
    int y=0;
  while(1)
  {
   cout<<"Please input an integer as this month"<<endl;
   cin>>y;
   if(cin.good()&&y>=1&&y<=12) return y;
   else
   {
       cout<<"Invalid input"<<endl;
       cin.clear( ); // 来清除错误状态
       cin.sync( ); // 换行
   }
  }
}
int input_day(year_date* a)
{
 int month=a->month,y=0;
  while(1)
  {
   cout<<"Please input an integer as this day"<<endl;
   cin>>y;
   if(cin.good()&&y>=1&&y<=a->day_number[month]) return y;
   else
   {
       cout<<"Invalid input"<<endl;
       cin.clear( ); // 来清除错误状态
       cin.sync();

   }
  }
}
int  input_number()
{
    int y=0;
  while(1)
  {
   cout<<"Please input an integer as the number you want to ask"<<endl;
   cin>>y;
   if(cin.good()) return y;
   else
   {
       cout<<"Invalid input"<<endl;
       cin.clear( ); // 来清除错误状态
       cin.sync( ); // 换行
   }
  }
}
