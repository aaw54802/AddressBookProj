#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
	if (year >= 1900)
		zYear = year;
	else
		zYear = 1900;

	if (1 <= month && month <= 12)
		zMonth = month;
	else
		zMonth = 1;

	int maxDays = get_num_days_month(); // Use the centralized logic to determine max days in the month

	if (1 <= day && day <= maxDays)
		zDay = day;
	else
		zDay = 1;
}

void dateType::print() const
{
	cout << zMonth << "-" << zDay << "-" << zYear;
}

int dateType::getMonth() const
{
	return zMonth;
}

int dateType::getday() const
{
	return zDay;
}

int dateType::getYear() const
{
	return zYear;
}

int dateType::get_num_days_month()
{
	int numDays;

	switch (zMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		numDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		numDays = 30;
		break;
	case 2: if (LeapYear())
		numDays = 29;
		  else
		numDays = 28;
	}

	return numDays;
}

bool dateType::LeapYear()
{

	if (((zYear % 4 == 0) && (zYear % 100 != 0)) || zYear % 400 == 0)
		return true;
	else
		return false;
}

dateType::dateType(int month, int day, int year)
{
	setDate(month, day, year);
}
