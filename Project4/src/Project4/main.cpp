#include<iostream>
#include"cp_date.h"
#include"cp_integer.h"
#include"integer_random_render.h"
using namespace std;
#define END_TURN 1000000000
int main(int argv, char* argc[])
{
	cp_date* today = new cp_date();
	today->date_input();
	today->date_output();
	while (1)
	{
		cp_integer* y = new cp_integer();
		while (1)
		{
			cout << "Do you want to get the date after some days?" << endl;
			cout << "Input 1 to continue, input 0 to quit the program." << endl;
			y->integer_input();
			if (y->num != 1 && y->num != 0) cout << "Invalid input, please try again." << endl;
			else break;
		}
		if (y->num == 1)
		{
			cout << "Now please input an integer n, as the days before or after the date" << endl;
			cout << "Positive n or 0 means n days after, while negative n means n days before." << endl;
			cp_integer* n = new cp_integer();
			n->integer_input();
			today->date_get(n->num);
			delete(y);
		}
		else
		{
			delete(y);
			break;
		}
	}
	delete(today);
	cout << "Ending the Program..." << endl;
	for (int i = 1; i <= END_TURN; i++);
	return 0;
}
