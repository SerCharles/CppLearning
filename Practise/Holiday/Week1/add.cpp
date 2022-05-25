#include<iostream>
using namespace std;
#include "add.h"
#define min_even 2
int add_even_numbers(int n)
{
    int max_even=0,time=0,result=0;
    if(n%2==0) max_even=n;
    else max_even=n-1;
    time=max_even/2;
    result=(min_even+max_even)*time/2;
    return result;
}