#pragma once
#include <iostream>
using namespace std;
class TimeHMS
{

	friend ostream& operator <<(ostream& c, const TimeHMS& t);
	friend istream& operator >>(istream& c,  TimeHMS& t);

private:
	int hour, min, sec;
public:
	TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}


	//연산자 오버로딩 함수들
	const TimeHMS operator +(const TimeHMS& operand) const
	{
		TimeHMS t;
		t.sec = sec + operand.sec;
		t.min = min + operand.min;
		t.hour = hour + operand.hour;

		t.min = t.min + (t.sec / 60);
		t.sec = t.sec % 60;

		t.hour = t.hour + (t.min / 60);
		t.min = t.min % 60;

		return t;
	}

	const TimeHMS operator -(const TimeHMS& operand) const
	{
		TimeHMS t;
		if (hour > operand.hour)
		{
			t.sec = sec - operand.sec;
			t.min = min - operand.min;
			t.hour = hour - operand.hour;
		}
		else
		{
			t.sec = operand.sec - sec;
			t.min = operand.min - min;
			t.hour = operand.hour- hour;	
		}

		if (t.sec < 0)
		{
			t.sec += 60;
			t.min -= 1;
		}

		if (t.min < 0)
		{
			t.min += 60;
			t.hour -= 1;
		}

		return t;
	}

	bool operator ==(const TimeHMS& operand) const
	{
		return ((hour == operand.hour) &&
			(min == operand.min) &&
			(sec == operand.sec));
	}

	bool operator != (const TimeHMS& operand) const
	{
		return !(*this == operand);
	}

	TimeHMS operator ++()
	{
		hour += 1;
		return *this;
	}
	TimeHMS operator --()
	{
		hour -= 1;
		return *this;
	}

	const TimeHMS operator ++(int extra)
	{
		sec++;
		min += sec / 60;
		sec %= 60;
		hour += min / 60;
		min %= 60;
		return *this;
	}
	const TimeHMS operator --(int extra)
	{
		sec--;
		if (sec < 0)
		{
			sec += 60;
			min -= 1;
		}

		if (min < 0)
		{
			min += 60;
			hour -= 1;
		}
		return *this;
	}

	int operator [](int idx)
	{
		if (idx == 0)
		{
			return hour;
		}
		else if (idx == 1)
		{
			return min;
		}
		else if (idx == 2)
		{
			return sec;
		}
	}

	operator int()
	{
		return (hour * 3600) + (min * 60) + sec;
	}

	operator double()
	{
		double hour_d = double(hour);
		double min_d = double(min);
		double sec_d = double(sec);

		return (hour_d + (min_d / 60) + (sec_d / 3600));
	}

	const TimeHMS operator*(int num) const
	{
		TimeHMS t1;
		int second = ((hour * 3600) + (min * 60) + sec) * num;
		t1.hour = second / 3600;
		t1.min = (second % 3600) / 60;
		t1.sec = (second % 3600) % 60;

		return t1;
	}

};

const TimeHMS operator *(int num, const TimeHMS& operand)
{
	return operand*num;
}

ostream& operator <<(ostream& c, const TimeHMS& t)
{
	c << t.hour << "시" << t.min << "분" << t.sec << "초";
	return c;
}

istream& operator >>(istream& c,  TimeHMS& t)
{
	c >> t.hour >> t.min >> t.sec;

	return c;
}