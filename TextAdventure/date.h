#pragma once
#include <iostream>
#include <string>

#define string std::string


class date {
private:
	int day, month, year;

public:
	date ()
	{
		day = 0;
		month = 0;
		year = 0;
		std::cout << "Dafuq you assigning an empty date?";
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
