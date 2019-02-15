//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Calendar;	//	Forward declaration

class Date
{
public:
	enum Weekday { SUNDAY=1, MONDAY, TUESDAY, WEDNEDAY, THURSDAY, FRIDAY, SATURDAY };
	
	Date(unsigned int day, unsigned int month, unsigned int year);
	virtual ~Date() {};
	
	void DMY(unsigned int& day, unsigned int& month, unsigned int& year) const;

	void addDays(int d);
	void addMonths(int m);
	void addYears(int y);

	//
	//	Number of days that this date lies after Date dt.
	//
	int daysDiff(Date dt) const;

	Weekday weekday() const;
	bool isGBD() const;
	void rollToGBD();
	void addBusinessDays(unsigned int d);

	Date& operator++();
	Date operator++(int);
	bool operator!=(const Date& dt) const;
	bool operator<(const Date& dt) const;	//	Needed to allow Date's to be put into a set

	bool isGBD(const Calendar& cal) const;
	void rollToGBD(const Calendar& cal);

private:
	bool isLeapYear(unsigned int year) const;

	unsigned int m_serial;
};

std::ostream& operator<<(std::ostream &stream, Date dt);

#endif
