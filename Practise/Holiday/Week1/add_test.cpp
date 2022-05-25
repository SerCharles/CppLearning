#include<iostream>
#include"add_test.h"
using namespace std;
void add_even_numbers_test()
{
    int n=0,ans=0;
	cout << "please input a number:" << endl;
   cin>>n;
   ans=add_even_numbers(n);
   cout << "input:" << n << endl;
   cout<<"output:" << ans << endl;
}