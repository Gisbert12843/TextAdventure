#include "date.h"
string getDateAsString (date pDate) // Format: "Day.Month.Year"
{
	string output = "";
	output = pDate.getDateDay () + '.' + pDate.getDateMonth () + '.' + pDate.getDateYear ();
	return output;
}


date getDateAsDateObj (int pDay, int pMonth, int pYear)
{
	date outputDate (pDay, pMonth, pYear);
	return outputDate;
}
date getDateAsDateObj (string pDateString)
{
	int Day = 0, Month = 0, Year = 0, mode = 1;
	string current = "";
	for ( char c : pDateString )
	{
		if ( c == '.' )
		{
			mode++;
			current = "";
		}
		switch ( mode )
		{
		case 1:
			current = current + c;
		case 2:
			Day = stoi (current);
			current = current + c;
		case 3:
			Month = stoi (current);
			current = current + c;

		default:
			break;
		}
	}
	Year = stoi (current);
	date outputDate (Day, Month, Year);
}