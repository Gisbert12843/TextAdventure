#pragma once
#include <string>
#include <iostream>
#include "date.h"

#define string std::string


class person {
private:
	string name;
	date birthdate;
	int age;

public:
	person (string pName, string pBirthdate)
	{
		name = pName;
		birthdate = getDateAsDateObj (pBirthdate);

	}

	int getCurrentAge (date pCurrentDate, date pBirthDate);

};