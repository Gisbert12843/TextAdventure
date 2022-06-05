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
	double height;

public:
	person (string pName, char pGender, double pHeight, string pBirthdate)
	{
		name = pName;
		gender = pGender;
		birthdate = getDateAsDateObj (pBirthdate);
		height = pHeight;
	}

	string getName () { return name; }
	char getGender () { return gender; }
	string getBirthdate () { getDateAsString (birthdate); }
	double getHeight () { return height; }

	int getCurrentAge (date pCurrentDate, date pBirthDate);
};