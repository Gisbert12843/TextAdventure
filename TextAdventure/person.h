#pragma once
#include <string>
#include <iostream>
#include "date.h"
#include <ctime> 
#include <vector>




class person {
private:
	std::string name;
	char gender;
	date birthdate;
	int age;
<<<<<<< HEAD
	double height;
	double weight;
	std::vector<Inventory> ownedInventories ={};
	Inventory personalInventory;


public:
	person() {
		name = "";
		age = 0;
		gender = 'n';
		birthdate = date(0,0,0);
		height = 0;
		weight = 0;
		std::cout << "Congrats, you successfully created a Ghost." << std::endl;
	}
	person (std::string pName, char pGender, double pHeight, double pWeight, std::string pBirthdate)
=======

public:
	person (string pName,char pGender, string pBirthdate)
>>>>>>> parent of ebfccf6 (0.21)
	{
		name = pName;
		gender = pGender;
		birthdate = getDateAsDateObj (pBirthdate);
<<<<<<< HEAD
		height = pHeight;
		weight = pWeight;
		std::string nameOfInv = "Trouses";
		Inventory newInventory("Trouses", 20, this);
		personalInventory = newInventory;
	}

	std::string getName () { return name; }
	char getGender () { return gender; }
	std::string getBirthdate () { getDateAsString (birthdate); }
	double getHeight () { return height; }

=======
	}

>>>>>>> parent of ebfccf6 (0.21)
	int getCurrentAge (date pCurrentDate, date pBirthDate);

};