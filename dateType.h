#pragma once

class dateType
{
public:

	//Constructor
	dateType(int month = 1, int day = 1, int year = 1900);

	//Precondition: a valid day, month, and year is supplied (see dayOfWeek)
	//Postcondition: stores them if valid, otherwise stores default
	void setDate(int month, int day, int year);

	//Postcondition: displays what the date is set to
	void print() const;

	//Postcondition: returns value of month
	int getMonth() const;

	//Postcondition: returns value of day
	int getday() const;

	//Postcondition: returns value of year
	int getYear() const;

	//Precondition: need the info to check for a leap year
	//Postcondition: sets the amount of days for each month in the year
	int get_num_days_month();

	//Postcondition: returns whether the year is a leap year or not
	bool LeapYear();



private:
	int zMonth;
	int zDay;
	int zYear;

};
