#include<iostream>
using namespace std;
#include "cp_two_integers.h"
void cp_two_integers::get_gcd_and_lcm()
{
	int a, b;
	if (num1 > num2)
	{
		a = num1; b = num2;
	}
	else
	{
		b = num1; a = num2;
	}
	//事先设定好a>=b
	while (b>0) //当小数b=0时，停止，a即为最小公倍数。
	{
		int temp = a % b; 
		a = b; b = temp;//如果b不为0，则GCD(a,b)=GCD(b,a%b),可用这个公式递归求解。
	}
	greatest_common_divisor = a;
	least_common_multiple = long long(num1) * long long(num2) / long long(a);
}
void cp_two_integers::print()
{
	cout << "The first number is " << num1 << endl;
	cout << "The second number is " << num2 << endl;
	cout << "Their greatest common divisor is " << greatest_common_divisor << endl;
	cout << "Their least common multiple is " << least_common_multiple << endl;
}
bool cp_two_integers::judge_gcd_and_lcm()
{
	int i, j;
	int a, b;
	if (num1 < num2)
	{
		a = num1;
		b = num2;
	}
	else
	{
		a = num2;
		b = num1;
	}
	if (a <=0 || b <= 0) return 0;//判断正整数
	if(a%greatest_common_divisor!=0||b%greatest_common_divisor!=0
		||least_common_multiple%a!=0||least_common_multiple%b!=0)//判断是否为公约，公倍数
	for (i = greatest_common_divisor+1; i <= a; i++)
	{
		if (a%i == 0 && b%i == 0) return 0;//判断有没有比它大的公约数
	}
	for (j = b; j < least_common_multiple; j++)
	{
		if (j%a == 0 && j%b == 0) return 0;//判断有没有比它小的公倍数
	}
	return 1;
}
