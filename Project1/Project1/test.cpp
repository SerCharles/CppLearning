#include<iostream>
#include"integer_random_render.h"
#include"cp_integer.h"
int test()
{
	int i,j;
	for (i = 1; i <= 100; i++)
	{
		int n = 0;
		if (i == 100) n = 2017013569;
		else n = integer_random_render(1, 10000);
		long long sum1 = 0, sum2 = 0;
		for (j = 1; j <= n; j++)
		{
			if (j % 2 == 0) sum1 += j;
		}
		sum2 = long long((n / 2 + 1))*long long((n / 2));
		if (sum1 != sum2) return 0;
	}
	
	return 1;
}