#include<iostream>
#include<cstring>
#include"cp_integer.h"
using namespace std;
int judge(char str[],bool positive);
int switch_to_int(char str[]);
void cp_integer::integer_output()
{
	cout << num << endl;
}
void cp_integer::integer_input()
{
	char str[20] = { 0 }; 
	int length = strlen(str);
	while (1)
	{
		num = 0;
		cout << "Please input an integer." << endl;
		cin >> str;
		fflush(stdin);
		//int   -2147483648бл2147483647 
		if (str[0] == '-')
		{
			if (judge(&str[1],0)==1)
			{
					num = 0 - switch_to_int(&str[1]);
					break;
			}	
			else if (judge(&str[1], 0) == 2)
			{
				num = 0-2147483648;
				break;
			}
		}
		else
		{
			if (judge(str,1))
			{
				num = switch_to_int(str);
				break;
			}
		}
		int i;
		for (i = 0; i <= 19; i++) str[i] = 0;
	}
}
int judge(char str[],bool positive)
{
	int length = strlen(str);
	if (str[0] == '0'&&str[1]!=0)
	{
		cout << "Invalid input, please try again." << endl;
		return 0;
	}
	if (length > 10)
	{
		cout << "Invalid input, please try again." << endl;
		return 0;
	}
	else
	{
		int i;
		for (i = 0; i < length; i++)
		{
			if (str[i] > '9' || str[i] < '0')
			{
				cout << "Invalid input, please try again." << endl;
				return 0;
			}
		}
		if (length == 10)
		{
			if (str[0] > '2')
			{
				cout << "Invalid input, please try again." << endl;
				return 0;
			}
			if (str[0] == '2')
			{
				int k = 1,n=0;
				for (i = 9; i >= 1; i--)
				{
					n += (str[i] - '0')*k;
					k *= 10;
				}
				if (positive == 1)
				{
					if (n > 147483647)
					{
						cout << "Invalid input, please try again." << endl;
						return 0;
					}
				}
				if (positive == 0)
				{
					if (n > 147483648)
					{
						cout << "Invalid input, please try again." << endl;
						return 0;
					}
					if (n == 147483648) return 2;
				}
			}
		}
	}
	return 1;
}
int switch_to_int(char str[])
{
	int k = 1, n = 0,i;
	int length = strlen(str);
	for (i = length-1; i >= 0; i--)
	{
		n += (str[i] - '0')*k;
		k *= 10;
	}
	return n;
}