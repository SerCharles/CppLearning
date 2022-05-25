#include<iostream>
using namespace std;
#include"complex.h"
complex operator + (complex& c1,complex& c2)
{
 complex c3;
 c3.real=c1.real+c2.real;
 c3.imagine=c1.imagine+c2.imagine;
 return c3;
}
complex operator - (complex& c1,complex& c2)
{
 complex c3;
 c3.real=c1.real-c2.real;
 c3.imagine=c1.imagine-c2.imagine;
 return c3;
}
complex operator * (complex& c1,complex& c2)
{
 complex c3;
 c3.real=c1.real*c2.real-c1.imagine*c2.imagine;
 c3.imagine=c1.real*c2.imagine+c1.imagine*c2.real;
 return c3;
}
complex operator / (complex& c1,complex& c2)
{
 double clength=c2.real*c2.real+c2.imagine*c2.imagine;
 complex c22,c3;
 c22.real=c2.real;c22.imagine=0-c2.imagine;
  c3.real=c1.real*c22.real-c1.imagine*c22.imagine;
 c3.imagine=c1.real*c22.imagine+c1.imagine*c22.real;
 c3.real/=clength;
 c3.imagine/=clength;
 return c3;
}