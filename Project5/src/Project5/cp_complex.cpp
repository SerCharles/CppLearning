#include<iostream>
#include"cp_complex.h"
using namespace std;
void cp_complex::get_value(double* a, double* b)
{
	*a = real;
	*b = imaginary;
}
void cp_complex::output_windows(char a[])
{
	cout <<a<< " = " << real << " + " << imaginary <<"i"<< endl;
}
void cp_complex::set_value(double a, double b)
{
	real = a;
	imaginary = b;
}

cp_complex operator + (cp_complex a, cp_complex b)
{
	cp_complex c ;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}
cp_complex operator - (cp_complex a, cp_complex b)
{
	cp_complex c ;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	return c;
}
cp_complex operator * (cp_complex a, cp_complex b)
{
	cp_complex c;
	c.real = a.real * b.real-a.imaginary*b.imaginary;
	c.imaginary = a.imaginary*b.real + a.real*b.imaginary;
	return c;
}
cp_complex operator / (cp_complex a, cp_complex b)
{
	cp_complex c ;
	if (b.real == 0 && b.imaginary == 0)
	{
		return c;
	}
	c.real = (a.real*b.real + a.imaginary*b.imaginary) / (b.real*b.real + b.imaginary*b.imaginary);
	c.imaginary = (a.imaginary*b.real - a.real*b.imaginary) / (b.real*b.real + b.imaginary*b.imaginary);
	return c;
}
cp_complex cp_complex::operator ++ () //前++
{
	cp_complex a ;
	real++;
	a.real = real;
	a.imaginary = imaginary;
	return a;
}
cp_complex cp_complex::operator -- () //前--
{
	cp_complex a ;
	real--;
	a.real = real;
	a.imaginary = imaginary;
	return a;
}
cp_complex cp_complex::operator ++ (int) //后++
{
	cp_complex a ;
	a.real = real;
	a.imaginary = imaginary;
	real++;
	return a;
}
cp_complex cp_complex::operator -- (int) //后--
{
	cp_complex a;
	a.real = real;
	a.imaginary = imaginary;
	real--;
	return a;
}