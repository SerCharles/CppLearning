#ifndef COMPLEX_H
#define COMPLEX_H
class complex
{
 public :
 double real,imagine;
 public:
 complex(){real=0;imagine=0;}
 ~complex(){}

 friend complex operator + (complex& c1,complex& c2);
 friend complex operator - (complex& c1,complex& c2);
 friend complex operator * (complex& c1,complex& c2);
 friend complex operator / (complex& c1,complex& c2);
};
extern void complex_test(complex c1,complex c2);















#endif