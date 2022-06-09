#pragma once
#include <iostream>
#include <string>
#include <cctype>


//#include "Inventory.h"
//#include "Object.h"
//#include "decisionInput.h"
//#include "date.h"
//#include "Person.h"

using std::string;

using std::cout; using std::endl;

namespace decision
{
	/*
	bool takeObject(Object pObjToBeTaken, Person pWhoTakesIt)
	{
		cout << "Yes = y | No = n" << endl;
		string decision = "";
		std::getline(std::cin, decision);
		std::transform(decision.begin(), decision.end(), decision.begin(),
			[](unsigned char c) { return std::tolower(c); });
		if ( decision == "n" || decision == "no" )
		{
			cout << "You are not taking the " << pObjToBeTaken.getName() << endl;
			return false;
		}
		else
			if ( decision == "y" || decision == "yes" )
			{
				cout << "You are taking the " << pObjToBeTaken.getName() << endl;

				pObjToBeTaken.setLocation(pWhoTakesIt.getInventory());
				pWhoTakesIt.getInventory()->addNewItemToInventory(&pObjToBeTaken);

				return true;
			}
			else
				takeObject(pObjToBeTaken, pWhoTakesIt);
	}
	*/
	
	
	string inputName(string displaytext)
	{
		string input = "";
		cout <<displaytext << endl;
		std::getline(std::cin, input);
		while ( !std::all_of(input.begin(), input.end(), ::isalpha) )
		{
			cout << "Input may only persist of letters." << endl;
			std::getline(std::cin, input);
		}
		return input;
	}

	int inputValue(string displaytext)
	{
		int value;
		string input = "";
		cout << displaytext << endl;
		std::getline(std::cin, input);
		while ( !std::all_of(input.begin(), input.end(), ::isdigit) )
		{
			cout << "Input may only persist of numbers." << endl;
			std::getline(std::cin, input);
		}
		value = std::stoi(input);
		return value;
	}
	char inputChar(string displaytext)
	{
		char input;
		cout << displaytext << endl;
		std::cin >> input;
		while ( !(input == 'm' || input == 'w' || input == 'n') )
		{
			cout << "Input may only persist of 'w','m' or 'n'." << endl;
			std::cin >> input;
		}
		return input;
	}

	
	//void createPlayerCharacter(Person **pPlayerCharacter)
	//{
	//	string Name = ""; char Gender = 'n'; double Height = 0;
	//	string Birthdate = "1.1.1"; Inventory *Inventory = nullptr;
	//	int mode = 0;
	//	while ( true )
	//	{
	//		switch ( mode )
	//		{
	//		case 0:
	//		{
	//			//Name = inputName("Please give a name to you Charakter.");
	//		}
	//		case 1:

	//		default:
	//			break;
	//		}
	//	}
	//	//manager::createNewPerson();
	//}
	
}