#pragma once
#include <string>
#include <iostream>
#include "date.h"
#include <ctime> 

#define string std::string


class person {
private:
	string name;
	char gender;
	date birthdate;
	int age;

public:
	person (string pName,char pGender, string pBirthdate)
	{
		name = pName;
		gender = pGender;
		birthdate = getDateAsDateObj (pBirthdate);
	}

	int getCurrentAge (date pCurrentDate, date pBirthDate);

};