#include<iostream>
#include<ctime>
#include"cp_time_by_clock.h"
using namespace std;
void cp_time_by_clock::get_time_start()
{
	m_time_start = clock();
}
void cp_time_by_clock::get_time_end()
{
	m_time_end = clock();
}
void cp_time_by_clock::get_time_total()
{
	clock_t d = m_time_end - m_time_start;
	double second, minisecond;
	int minute;
	/*if (d >= CLOCKS_PER_SEC * 60)
	{
		minute = int(d) / CLOCKS_PER_SEC/60;
		second = (double(d) - double(CLOCKS_PER_SEC * 60 * minute)) / CLOCKS_PER_SEC;
		cout << "Total time is " << minute << " minutes and " << second << " seconds." << endl;
	}*/
    if (d >= CLOCKS_PER_SEC / 10)
	{
		second = double(d) / double(CLOCKS_PER_SEC);
		cout << "Total time is " << second << " seconds;" << endl;
	}
	else
	{
		minisecond = double(d) ;
		cout << "Total time is " << minisecond << " milliseconds" << endl;
	}
}