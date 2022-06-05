#include "date.h"
#include <string>



string getDateAsString(date pDate) // Format: "Day.Month.Year"
{
	string output = "";
	output = std::to_string(pDate.getDateDay()) + '.' + std::to_string(pDate.getDateMonth()) + '.' + std::to_string(pDate.getDateYear());
	return output;
}


date getDateAsDateObj(int pDay, int pMonth, int pYear)
{
	date outputDate(pDay, pMonth, pYear);
	return outputDate;
}
date getDateAsDateObj(string pDateString)
{
	int Day = 0, Month = 0, Year = 0, mode = 1; //Mode beschreibt den Status ob grade für den Tag,Monat oder Jahr gesammelt wird
	string current = "";
	for ( char c : pDateString ) //Iteration durch den String
	{
		if ( c == '.' )//Check auf . im String
		{

			switch ( mode )
			{
			case 1:
				Day = stoi(current);
				current = "";
				break;
			case 2:
				Month = stoi(current);
				current = "";
				break;
			default:
				break;
			}
			mode++;
			continue;
		}
		switch ( mode )
		{
		case 1:
			current.push_back(c);
			break;
		case 2:
			current.push_back(c);
			break;
		case 3:
			current.push_back(c);
			break;

		default:
			break;
		}
	}
	Year = stoi(current);

	date outputDate(Day, Month, Year);
	return outputDate;
}
date getCurrentDate()
{

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Month = 1 + newtime.tm_mon;
	int Day = newtime.tm_mday;
	int Year = newtime.tm_year + 1900;
	date currentDate(Day, Month, Year);
	return currentDate;
}
