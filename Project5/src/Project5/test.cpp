#include<iostream>
#include"cp_complex.h"
#include<fstream>
#include"cp_unit_test.h"
#include"test.h"
using namespace std;
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void cp_complex::output_file()
{
	out << real << " + " << imaginary << " i    " ;
}
void test()
{
	int n;
	in >> n;
	for (int i = 1; i <= n; i++)
	{
		int j;
		double p, q;
		bool whether = 1;
		cp_complex numbers[12];
		double result_1[12], result_2[12];
		//out << "a   b   a+b   a-b   a*b   a/b   c   d   e   f   g" << endl;
		for (j = 1; j <= 11; j++)
		{
			in >> p >> q;
			result_1[j] = p; result_2[j] = q;
		}
		numbers[1].set_value(result_1[1], result_2[1]);
		numbers[2].set_value(result_1[2], result_2[2]);
		cp_complex a, b;
		a.set_value(result_1[1], result_2[1]);
		b.set_value(result_1[2], result_2[2]);
		numbers[3] = a + b;
		numbers[4] = a - b;
		numbers[5] = a * b;
		numbers[6] = a / b;
		numbers[7] = ++a;
		numbers[8] = a++;
		numbers[9] = ++a;
		numbers[10] = a--;
		numbers[11] = --a;
		for (j = 1; j <= 11; j++)
		{
			double t1, t2;
			numbers[j].get_value(&t1, &t2);
			cp_unit_test* test_1 = new cp_unit_test(t1, result_1[j], 0.001);
			cp_unit_test* test_2 = new cp_unit_test(t2, result_2[j], 0.001);
			if (test_1->compare() == 0 || test_2->compare() == 0) whether = 0;
			delete(test_1); delete(test_2);
		}
		out << "set " << i << endl;
		for (j = 1; j <= 11;j++)
		{
			out << result_1[j] << " + " << result_2[j] << " i    ";
		}
		out << "\n";
		for (j = 1; j <= 11; j++)
		{
			numbers[j].output_file();
		}
		out << "\n";
		if (whether == 1) out << "Accepted" << endl;
		else out <<"Wrong Answer" << endl;
		//char num[12][6] = { " ","a","b","a + b","a - b","a * b","a / b","c","d","e","f","g" };
		//char pl[] = { "a + b" }, mi[] = { "a - b" }, mul[] = { "a * b" }, div[] = { "a / b" };
		//char cc[] = "c", dd[] = "d", ee[] = "e", ff[] = "f", gg[] = "g";
	}
}