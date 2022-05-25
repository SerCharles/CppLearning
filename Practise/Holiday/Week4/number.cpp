#include<iostream>
#include"number.h"
using namespace std;
int numbers::get_max_divide()
{
   int min=0;
   if(numbers::num_a<numbers::num_b) min=numbers::num_a;
   else min=numbers::num_b;
   int i=0;
   for(i=min;i>=1;i--)
   {
       if(numbers::num_a%i==0&&numbers::num_b%i==0) return i;
   }
}
int numbers::get_min_multiply()
{
 int a1=numbers::num_a/numbers::max_divide,a2=numbers::num_b/numbers::max_divide;
 int i;
 i=a1*a2*numbers::max_divide; 
return i;
}