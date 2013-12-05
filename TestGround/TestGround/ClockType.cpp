#include <iostream>
#include "ClockType.h"
using namespace Time;

/////////////////////////////////////////////////////////////////
ClockType::ClockType()
{
	this->Hours = 0;
	this->Minutes = 0;
	this->Seconds = 0;
	return;
}

/////////////////////////////////////////////////////////////////
ClockType::ClockType(int hr, int min, int sec)
{
	this->Hours = hr;
	this->Minutes = min;
	this->Seconds = sec;
	return;
}

/////////////////////////////////////////////////////////////////
ClockType::~ClockType()
{
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::SetTime(int hours, int minutes, int seconds)
{
	this->Hours = hours;
	this->Minutes = minutes;
	this->Seconds = seconds;
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::GetTime(int& hours, int& minutes, int& seconds) const
{
	hours = this->Hours;
	minutes = this->Minutes;
	seconds = this->Seconds;
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::PrintTime() const
{
	using std::cout;
	using std::endl;
	cout << "The time is: " << this->Hours 
		<< ":" << this->Minutes 
		<< ":" << this->Seconds << endl;
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::IncrementHours()
{
	++(this->Hours);
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::IncrementMinutes()
{
	++(this->Minutes);
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::IncrementSeconds()
{
	++(this->Seconds);
	return;
}

/////////////////////////////////////////////////////////////////
void ClockType::operator=(ClockType& rhClock)
{
	this->Hours = rhClock.Hours;
	this->Minutes = rhClock.Minutes;
	this->Seconds = rhClock.Seconds;
}

/////////////////////////////////////////////////////////////////
bool ClockType::operator==(ClockType& rhClock)
{
	bool areEqual = false;
	if(this->Hours == rhClock.Hours)
	{
		if(this->Seconds == rhClock.Seconds)
		{
			if(this->Minutes == rhClock.Minutes)
			{
				areEqual = true;
			}
		}
	}
	return areEqual;
}

/////////////////////////////////////////////////////////////////
bool ClockType::operator!=(ClockType& rhClock)
{
	return !(*this == rhClock);
}