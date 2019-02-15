//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#include "calendar.h"

void Calendar::addHoliday(Date dt)
{
	m_dates.insert(dt);
	return;
}

bool Calendar::isHoliday(Date dt) const
{
	return (m_dates.find(dt) != m_dates.end());
}