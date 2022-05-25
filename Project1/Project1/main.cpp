#include<iostream>
#include"cp_integer.h"
#include"test.h"
using namespace std;
int main(int argc,char* argv[])
{
	cp_integer* n = new cp_integer();
	while (1)
	{
		n->integer_input();
		if (n->num <= 0)
		{
			cout << "Invalid input, please try again." << endl;
		}
		else break;
	}
	long long i, sum1 = 0, sum2 = 0;
		for (i = 1; i <= n->num; i++)
		{
			if (i % 2 == 0) sum1 += i;
		}

		sum2 = long long((n->num/2+1))*long long((n->num/2));
		cout << "Using method 1,the answer is "<<sum1<<"."<<endl;
		cout << "Using method 2,the answer is " << sum2 << "." << endl;
		if(sum1==sum2) cout << "The answers of the two methods are the same" << endl;
		else  cout << "The answers of the two methods are different" << endl;
		cout << "After testing 100 datas,\nit turns out that";
		if (test())
		{
			cout << " the answers of the two methods are always the same" << endl;
		}
		else cout << " the answers of the two methods are not always the same"<<endl;
		/*cout << "Our Conquest is the Sea of Stars!" << endl;
		cout << "             Keep\n             Calm\n             And\n          Fight For\n             NEYC\n";*/
	while (1);
	return 0;
}