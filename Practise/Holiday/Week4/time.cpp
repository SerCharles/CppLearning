#include<iostream>
#include"time.h"
using namespace std;
double time1::get_total_time()
{
   clock_t duration=time1::clock_end-time1::clock_start;
   double total;
   const double clock_run=1000;
   total=double(duration)/clock_run;
   return total;
}
void time1::get_clock_end()
{
  time1::clock_end=clock();
}
void time1::get_clock_start()
{
  time1::clock_start=clock();
}
