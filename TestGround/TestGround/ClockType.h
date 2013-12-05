#ifndef CLOCK_TYPE_H
#define CLOCK_TYPE_H

namespace Time
{
	class ClockType
	{
	public:
		ClockType();
		ClockType(int hr, int min, int sec);
		~ClockType();
		void SetTime(int hours, int minutes, int seconds);
		void GetTime(int& hours, int& minutes, int& seconds) const;
		void PrintTime() const;
		void IncrementHours();
		void IncrementMinutes();
		void IncrementSeconds();
		void operator=(ClockType& rhClock);
		bool operator==(ClockType& rhClock);
		bool operator!=(ClockType& rhClock);
	private:
		unsigned short Hours;
		unsigned short Minutes;
		unsigned short Seconds;
	};
}
#endif
