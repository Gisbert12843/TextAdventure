#include "Person.h"




int Person::getCurrentAge(date pBirthDate, date pCurrentDate)
{
	pBirthDate = this->birthdate;
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

Person::Person(string pName, char pGender, double pHeight, string pBirthdate, Inventory *pInventory)
{
	name = pName;
	gender = pGender;
	birthdate = getDateAsDateObj(pBirthdate);
	height = pHeight;
	ownedInventory = pInventory;
	age = getCurrentAge(this->birthdate, getCurrentDate());
}