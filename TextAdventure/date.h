#pragma once
class date {
private:
	int day, month, year;

public:
	date (int pDay, int pMonth, int pYear) {
		day = pDay;
		month = pMonth;
		year = pYear;
	}
	int getDateDay () {
		return day;
	}
	int getDateMonth () {
		return month;
	}
	int getDateYear () {
		return year;
	}
};

date getDateObject ();