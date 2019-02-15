//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _CALENDAR_H_
#define _CALENDAR_H_

#include <set>
#include "date.h"

class Calendar
{
public:
	void addHoliday(Date dt);
	bool isHoliday(Date dt) const;
private:
	std::set<Date> m_dates;
};

#endif
