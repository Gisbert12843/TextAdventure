#include "person.h"

int person::getCurrentAge(date pCurrentDate, date pBirthDate)
{
	int returnvalue = 0;
	int month_difference = pCurrentDate.getDateMonth() - pBirthDate.getDateMonth();

	if ( month_difference < 0 )
	{
		returnvalue = pCurrentDate.getDateYear() - pBirthDate.getDateYear() - 1;
	}
	else if ( month_difference == 0 )
	{
		if ( pCurrentDate.getDateDay() < pBirthDate.getDateDay() )
		{
			returnvalue = pCurrentDate.getDateYear() - pBirthDate.getDateYear() - 1;
		}
	}
	else
		returnvalue = pCurrentDate.getDateYear() - pBirthDate.getDateYear();
	return returnvalue;
}