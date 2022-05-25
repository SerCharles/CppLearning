#include<iostream>
#include"time.h"
#include"number.h"
using namespace std;
void input(int* a,int* b);
int main(int argc, char* args[ ])
{
    numbers num;
    time1 t;
   cout<<"Please input two integers"<<endl;
   cin>>num.num_a>>num.num_b;
   const int total_rounds=1000000;
   int i;
   t.get_clock_start();
   for(i=1;i<=total_rounds;i++)
   {
   num.max_divide=num.get_max_divide();
   num.min_multiply=num.get_min_multiply();
   }
   t.get_clock_end();
   t.total_time=t.get_total_time();
   cout<<"num a is "<<num.num_a<<endl;
   cout<<"num b is "<<num.num_b<<endl;
   cout<<"their GCM is "<<num.max_divide<<endl;
   cout<<"their LCM is "<<num.min_multiply<<endl;
   cout<<"Total time is "<<t.total_time<<"ms"<<endl;
   return 0;
}
