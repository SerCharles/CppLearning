#include<iostream>
#include<string>
#include"cp_longint.h"
#include<cmath>
using namespace std;
int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}
void cp_longint::setvalue(string &a)
{
	int length = a.size();
	int minus_num = 0;
	bool whether = 0;
	if (length == 0)
	{
		number.clear();
		number.push_back('0');
		return;
	}
	if (length == 1 && a[0] == '\n')
	{
		number.clear();
		number.push_back('0');
		return;
	}
		number.clear();
		int i;
		for (i = 0; i < length; i++)
		{
			if (a[i] >= '1'&&a[i] <= '9')
			{
				whether = 1;
				number.push_back(a[i]);
			}
			else if (a[i] == '0'&&whether == 1)
			{
				number.push_back(a[i]);
			}
			else if (a[i] == '-'&&whether == 0)
			{
				minus_num++;
			}
		}
		if (minus_num % 2 == 1) sign = -1;
		else sign = 1;
		if (number.size() == 0)
		{
			number.push_back('0');
		}
		if (number.size() == 1 && number[0] == '0') sign = 0;
}
void cp_longint::inputvalue()
{
	char a[1000];
	cout << "Please input a line of string as the num" << endl;
	cin >> a;
	string temp(a);
	setvalue(temp);
}
void cp_longint::outputvalue()
{
	cout << "The integer is: ";
	if (sign == 1) cout << '+';
	if(sign==-1) cout << '-';
	cout << number<<endl;
}
cp_longint operator + (cp_longint a, cp_longint b)
{
	cp_longint c;
	if (a.sign == 0 && b.sign == 0) return c;
	else if (a.sign == 0) return b;
	else if (b.sign == 0) return a;
	else if (a.sign == b.sign)
	{
		int i;
		c.sign = a.sign;
		if (a.number.size() < b.number.size()) a.number.insert(a.number.begin(), b.number.size() - a.number.size(), '0');
		if (a.number.size() > b.number.size()) b.number.insert(b.number.begin(), a.number.size() - b.number.size(), '0');
		for (i = 0; i <a.number.size(); i++)
		{
			int temp = a.number[a.number.size() -1- i] - '0' + b.number[b.number.size() -1- i] - '0'+c.number[i]-'0';
			int temp1 = temp % 10, temp2 = temp / 10;
			c.number[i] = temp1 + '0';
			c.number.push_back('0' + temp2);	
		}
		while (1)
		{
			if (c.number[c.number.size() - 1] == '0') c.number.erase(c.number.size() - 1);
			else break;
		}
		reverse(c.number.begin(), c.number.end());
		return c;
	}
	else if (a.sign != b.sign)
	{
		int i;
		if (a.number.size() < b.number.size()) a.number.insert(a.number.begin(), b.number.size() - a.number.size(), '0');
		if (a.number.size() > b.number.size()) b.number.insert(b.number.begin(), a.number.size() - b.number.size(), '0');
		int whether = a.number.compare(b.number);
		if (whether == 0)
		{
			c.sign = 0;
			c.number.clear();
			c.number.push_back('0');
			return c;
		}
		else if (whether < 0)
		{
			c.sign = b.sign;
			swap(a.number, b.number);
		}
		else
		{
			c.sign = a.sign;
		}
		for (i = 0; i <a.number.size(); i++)
		{
			int temp = a.number[a.number.size() - 1 - i] - b.number[b.number.size() - 1 - i] + c.number[i] - '0';
			int temp1, temp2;
			if (temp < 0)
			{
				temp1 = temp + 10; temp2 = -1;
			}
			else
			{
				temp1 = temp; temp2 = 0;
			}
			c.number[i] = temp1 + '0';
			c.number.push_back('0' + temp2);
		}
		while (1)
		{
			if (c.number[c.number.size() - 1] == '0') c.number.erase(c.number.size() - 1);
			else break;
		}
		reverse(c.number.begin(), c.number.end());
		return c;
	}
}
cp_longint operator - (cp_longint a, cp_longint b)
{
	cp_longint c;
	if (a.sign == 0 && b.sign == 0) return c;
	else if (a.sign == 0)
	{
		b.sign = 0 - b.sign;
		return b;
	}
	else if (b.sign == 0) return a;
	else if (a.sign != b.sign)
	{
		if (a.sign == 1) c.sign = 1;
		else c.sign = -1;
		int i;
		if (a.number.size() < b.number.size()) a.number.insert(a.number.begin(), b.number.size() - a.number.size(), '0');
		if (a.number.size() > b.number.size()) b.number.insert(b.number.begin(), a.number.size() - b.number.size(), '0');
		for (i = 0; i <a.number.size(); i++)
		{
			int temp = a.number[a.number.size() - 1 - i] - '0' + b.number[b.number.size() - 1 - i] - '0' + c.number[i] - '0';
			int temp1 = temp % 10, temp2 = temp / 10;
			c.number[i] = temp1 + '0';
			c.number.push_back('0' + temp2);
		}
		while (1)
		{
			if (c.number[c.number.size() - 1] == '0') c.number.erase(c.number.size() - 1);
			else break;
		}
		reverse(c.number.begin(), c.number.end());
		return c;
	}
	else if (a.sign == b.sign)
	{
		int i;
		if (a.number.size() < b.number.size()) a.number.insert(a.number.begin(), b.number.size() - a.number.size(), '0');
		if (a.number.size() > b.number.size()) b.number.insert(b.number.begin(), a.number.size() - b.number.size(), '0');
		int whether = a.number.compare(b.number);
		if (whether == 0)
		{
			c.sign = 0;
			c.number.clear();
			c.number.push_back('0');
			return c;
		}
		else if (whether < 0)
		{
			c.sign = 0-b.sign;
			swap(a.number, b.number);
		}
		else
		{
			c.sign = a.sign;
		}
		for (i = 0; i <a.number.size(); i++)
		{
			int temp = a.number[a.number.size() - 1 - i] - b.number[b.number.size() - 1 - i] + c.number[i] - '0';
			int temp1, temp2;
			if (temp < 0)
			{
				temp1 = temp + 10; temp2 = -1;
			}
			else
			{
				temp1 = temp; temp2 = 0;
			}
			c.number[i] = temp1 + '0';
			c.number.push_back('0' + temp2);
		}
		while (1)
		{
			if (c.number[c.number.size() - 1] == '0') c.number.erase(c.number.size() - 1);
			else break;
		}
		reverse(c.number.begin(), c.number.end());
		return c;
	}
}
cp_longint operator * (cp_longint a, cp_longint b)
{
	cp_longint c;
	if (a.sign == 0 || b.sign == 0)
	{
		c.number.clear();
		c.number.push_back('0');
		c.sign = 0;
		return c;
	}
	else
	{
		if (a.sign == b.sign) c.sign = 1;
		else c.sign = -1;
		int i, j;
		c.number.insert(c.number.end(), a.number.size()+b.number.size()+10, '0');
		for (j = 0; j < b.number.size(); j++)
		{
			for (i = 0; i < a.number.size(); i++)
			{
				int temp = c.number[j + i] - '0' + (a.number[a.number.size()-1-i] - '0')*(b.number[b.number.size()-1-j] - '0');
				int temp1 = temp % 10, temp2 = temp / 10;
				c.number[j + i] = temp1 + '0';
				c.number[j + i + 1] += temp2;
			}
		}
		while (1)
		{
			if (c.number[c.number.size() - 1] == '0') c.number.erase(c.number.size() - 1);
			else break;
		}
		if (c.number[c.number.size() - 1] > '9')
		{
			int temp = c.number[c.number.size() - 1] / 10;
			c.number[c.number.size() - 1] %= 10;
			c.number.push_back(temp);
		}
		reverse(c.number.begin(), c.number.end());
		return c;
	}
}