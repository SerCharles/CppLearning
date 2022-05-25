#include<iostream>
using namespace std;
#include"complex.h"

void complex_test(complex c1,complex c2)
{
 cout<<"c1=("<<c1.real<<","<<c1.imagine<<")"<<endl;
 cout<<"c2=("<<c2.real<<","<<c2.imagine<<")"<<endl;
 complex cplus,cminus,cmulti,cdivide;
 cplus=c1+c2;
 cminus=c1-c2;
 cmulti=c1*c2;
cout<<"c1+c2=("<<cplus.real<<","<<cplus.imagine<<")"<<endl;
cout<<"c1-c2=("<<cminus.real<<","<<cminus.imagine<<")"<<endl;
cout<<"c1*c2=("<<cmulti.real<<","<<cmulti.imagine<<")"<<endl;
if(c2.real==0&&c2.imagine==0)
{
    cout<<"cannot calculate c1/c2,c2 cannot be 0"<<endl;
}
else
{
cdivide=c1/c2;
cout<<"c1/c2=("<<cdivide.real<<","<<cdivide.imagine<<")"<<endl;
}
}
int main(int argc,char* argv[])
{
    complex a,b;
    cout<<"Please input complex number a"<<endl;
    cout<<"a's real number: ";
    cin>>a.real;
    cout<<endl;
    cout<<"a's imagine number: ";
    cin>>a.imagine;
    cout<<endl;
    cout<<"Please input complex number b"<<endl;
    cout<<"b's real number: ";
    cin>>b.real;
    cout<<endl;
    cout<<"b's imagine number: ";
    cin>>b.imagine;
    cout<<endl;
    complex_test(a,b);
    return 0;
}