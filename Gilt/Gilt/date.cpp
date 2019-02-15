//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#include <cmath>
#include <string>
#include <map>

#include "date.h"
#include "calendar.h"
#include "error.h"

//	Days in each month in a leap year
static unsigned int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned int min(unsigned int x, unsigned int y)
{
	return x<y ? x : y;
}

bool Date::isLeapYear(unsigned int year) const
{
	//	Years that are multiples of 4 are leap years.
	//	However, multiples of 100 are NOT leap years.
	//	But multiples of 400 ARE leap years.
	//
	//	Our implementation is designed to be consistent with Excel,
	//	and is correct for the years 1901 to 2099 (and so is fine for all practical purposes).
	//	But, like Excel, it gives an incorrect result for the year 1900. 
	//
	return (year % 4 == 0);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	//
	//	Cumulative days in previous months
	//
	static const unsigned int f[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

	//
	//	Validation of input values
	//
	if (year < 1900)
	{
		fatalError("Date::Date() cannot handle dates before year 1900");
	}
	if (month < 1 || month > 12)
	{
		fatalError("Date::Date() passed an invalid month");
	}
	if (day < 1 || day > daysInMonth[month-1])
	{
		fatalError("Date::Date() passed an invalid day");
	}
	if (!isLeapYear(year) && month == 2 && day == 29)
	{
		fatalError("Date::Date() passed an invalid day");
	}
	
	m_serial = (year - 1900) * 365 + static_cast<int>((year - 1897) / 4) + f[month-1] + day;

	if (month > 2 && isLeapYear(year))
	{
		++m_serial;
	}
}

void Date::DMY(unsigned int& day, unsigned int& month, unsigned int& year) const
{
	static const double EPSILON = 0.00000001;
	static const double N1 = 365.25;
	static const double N2 = 2447.0 / 80.0;

	//	Move base to 29/2/1900 (this will be <0 for first 2 months of 1900)
	const int serialAdj = m_serial - 60;

	//	Number of whole years that have passed since 29/2/1900
	const int g = static_cast<int>(floor((serialAdj - EPSILON) / N1));

	//	Days since most recent last date in february, plus dummy zero month of 30 days
	const int c = serialAdj - static_cast<int>(floor(g * N1)) + 30;

	//	Number of months after February (1 to 12)
	const unsigned int p = static_cast<unsigned int>(floor(c / N2));

	//	Determine outputs
	day = c - static_cast<unsigned int>(N2 * p);
	month = p + 2;
	year = g + 1900;

	if (p >= 11)
	{
		month -= 12;
		++year;
	}
	return;
}

void Date::addDays(int d)
{
	if ( m_serial + d < 1 )
		fatalError("Date::addDays() takes date to before base date!");

	m_serial += d;
}

void Date::addMonths(int m)
{
	unsigned int day = 0, month = 0, year = 0;
	DMY(day, month, year);

	int newMonth = month + m;	//	N.B. This can be negative

	//
	//	Calculate number of whole years to shift
	//
	const int n = static_cast<int>(floor((newMonth-1.0)/12.0));
	newMonth -= 12 * n;
	year += n;

	//
	//	Check day is not beyond end of month,
	//	else roll back to last actual day of month.
	//
	day = min(day, daysInMonth[newMonth-1]);
	if (!isLeapYear(year) && newMonth == 2 && day == 29)
	{
		--day;
	}
	m_serial = Date(day, newMonth, year).m_serial;
}

void Date::addYears(int y) 
{
	unsigned int day = 0, month = 0, year = 0;
	DMY(day, month, year);

	const int newYear = year + y;	//	N.B. This can be negative (although not valid later)

	if (!isLeapYear(newYear) && month == 2 && day == 29)
	{
		--day;
	}
	m_serial = Date(day, month, newYear).m_serial;
}

int Date::daysDiff(Date dt) const
{
	return m_serial - dt.m_serial;
}

Date::Weekday Date::weekday() const
{
	unsigned int x = m_serial % 7;
	if (x == 0) x = 7;	//	By convention
	return static_cast<Date::Weekday>(x);
}

bool Date::isGBD() const
{
	const Date::Weekday wd = weekday();
	return (wd != SATURDAY && wd != SUNDAY);
}

void Date::rollToGBD()
{
	while (!isGBD())
		++m_serial;
}

void Date::addBusinessDays(unsigned int d)
{
	//
	//	N.B. This function can only roll forward (d >= 0)
	//
	for (unsigned int i = 0; i < d; ++i)
	{
		++m_serial;
		rollToGBD();
	}
}

Date& Date::operator++()	//	This is ++d
{
	++m_serial;
	return *this;
}

Date Date::operator++(int)	//	This is d++
{
	Date temp = *this;
	++m_serial;
	return temp;
}

bool Date::operator!=(const Date& dt) const
{
	return m_serial != dt.m_serial;
}

bool Date::operator<(const Date& dt) const
{
	return m_serial < dt.m_serial;
}

bool Date::isGBD(const Calendar& cal) const
{
	return isGBD() && !cal.isHoliday(*this);
}

void Date::rollToGBD(const Calendar& cal)
{
	while (!isGBD(cal))
		++m_serial;
}

std::ostream& operator<<(std::ostream &stream, Date dt)
{
	unsigned int d = 0, m = 0, y = 0;
	dt.DMY(d, m, y);
	stream << d << "/" << m << "/" << y;
	return stream;
}
