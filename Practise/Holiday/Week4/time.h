#ifndef TIME_H
#define TIME_H
#include<ctime>
class time1
{
  public:
  clock_t clock_start,clock_end;
  double total_time;
  public:
  time1(){clock_start=clock();clock_end=clock_start;}
  ~time1(){}
  double get_total_time();
  void get_clock_start();
  void get_clock_end();
};

#endif
