#pragma once
#include <iostream>
#include <string>

using std::string;



class date {
private:
	int day, month, year;

public:
	date ()
	{
		day = 0;
		month = 0;
		year = 0;
	};
	date (int pDay, int pMonth, int pYear)
	{
		day = pDay;
		month = pMonth;
		year = pYear;
	}
	int getDateDay ()
	{
		return day;
	}
	int getDateMonth ()
	{
		return month;
	}
	int getDateYear ()
	{
		return year;
	}
};

date getDateAsDateObj (int pDay, int pMonth, int pYear);
date getDateAsDateObj (string pDateString);
string getDateAsString (date pDate);
date getCurrentDate ();

int getDateDifference(date pEarlyerDate, date pCurrentDate);
