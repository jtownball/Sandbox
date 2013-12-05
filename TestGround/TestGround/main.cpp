#include <iostream>
#include <vector>
#include "ClockType.h"
using Time::ClockType;
using std::vector;

int main()
{
	ClockType Clk1; //empty constructor
	ClockType Clk2(1,2,3); //parameterized constructor

	Clk1.PrintTime();
	Clk2.PrintTime();

	if(Clk1 != Clk2)
	{
		Clk1 = Clk2;
	}


	Clk1.PrintTime();
	Clk2.PrintTime();

	ClockType* tempClock;
	vector<ClockType> clocks;
	for(int i = 0; i < 100; ++i)
	{
		tempClock = new ClockType();
		clocks.push_back(*tempClock);
	}

	for(int i = 0; i < clocks.size(); ++i)
	{
		clocks[i].PrintTime();
		tempClock = &clocks.back();
		clocks.pop_back();
		delete tempClock;
		tempClock = NULL;
	}

	system("PAUSE");
	return 0;
}