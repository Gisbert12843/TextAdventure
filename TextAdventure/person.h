#pragma once
#include <string>
#include <iostream>
#include "date.h"
#include <ctime> 

#define string std::string


class Person {
private:
	string name;
	char gender;
	date birthdate;
	int age;
	double height;

public:
	Person (string pName, char pGender, double pHeight, string pBirthdate)
	{
		name = pName;
		gender = pGender;
		birthdate = getDateAsDateObj (pBirthdate);
		height = pHeight;
	}

	string getName () { return name; }
	char getGender () { return gender; }
	string getBirthdate () { return getDateAsString (birthdate); }
	double getHeight () { return height; }
	void takeObject(Object pObjToBeTaken) { ; }

	int getCurrentAge(date pBirthDate, date pCurrentDate = getCurrentDate());
};