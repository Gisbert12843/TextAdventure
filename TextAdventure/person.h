#pragma once
#include <string>
#include <iostream>
#include "date.h"
#include <ctime>
#include <vector>

#include "Object.h"
#include "Inventory.h"

using std::string; using std::vector;


class Inventory;

class Person {
private:
	string name;
	char gender;
	date birthdate;
	int age;
	double height;
	Inventory *ownedInventory = nullptr;

public:
	
	Inventory *getInventory() { return ownedInventory; }
	string getName () { return name; }
	char getGender () { return gender; }
	string getBirthdate () { return getDateAsString (birthdate); }
	double getHeight () { return height; }
	

	int getCurrentAge(date pBirthDate, date pCurrentDate = getCurrentDate());
	Person(string pName = "", char pGender = 'n', double pHeight = 0, string pBirthdate = "1.1.1", Inventory *pInventory = nullptr);

};


