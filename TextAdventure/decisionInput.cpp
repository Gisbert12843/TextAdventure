#include "decisionInput.h"
namespace decisionInput
{
	bool takeObject(Object pObjToBeTaken, Person pWhoTakesIt)
	{
		cout << "Yes = y | No = n" << endl;
		string decision = "";
		cin.clear(); cin.sync();
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

	string inputName(string displaytext)
	{
		string input = "";
		cout << displaytext << endl;
		cin.clear(); cin.sync();
		std::getline(std::cin, input);
		while ( !std::all_of(input.begin(), input.end(), ::isalpha) )
		{
			cout << "Input may only persist of letters." << endl;
			std::getline(std::cin, input);
		}
		return input;
	}
	string inputDate(string displaytext) //Still needs way more errorhandling!
	{
		string input = "";
		cout << displaytext << endl;
		cin.clear(); cin.sync();
		std::getline(std::cin, input);
		while ( std::all_of(input.begin(), input.end(), ::isalpha) )
		{
			cout << "Input may only persist of numbers and dots." << endl;
			std::getline(std::cin, input);
		}
		return input;
	}
	double inputValue(string displaytext)
	{
		double value;
		string input = "";
		cout << displaytext << endl;
		cin.clear(); cin.sync();
		std::getline(std::cin >> std::ws, input);
		while ( input.empty() && std::find_if(input.begin(),
			input.end(), [](char c) { return !(std::isdigit(c) || c == '.');  }) == input.end() ) //This validates a string as a working double
		{
			cout << "Input may only persist of numbers of the format (x.x)." << endl;
			std::getline(std::cin, input);
		}
		const char *c = input.c_str();    
		value = atof(c);
		return value;
	}
	char inputChar(string displaytext)
	{
		char input;
		cout << displaytext << endl;
		std::cin >> input;
		while ( !(input == 'm' || input == 'w' || input == 'd') )
		{
			cout << "Input may only persist of 'w','m' or 'n'." << endl;
			std::cin >> input;
		}
		return input;
	}



	bool createPlayerCharacter(Person **pPlayerCharacter)
	{
		string Name = ""; char Gender = 'n'; double Height = 0;
		string Birthdate = getDateAsString(getCurrentDate()); Inventory *Inventory = nullptr;
		int mode = 0;

		switch ( mode )
		{
		case 0:
		{
			Name = inputName("Please give the name of your Character.");
		}
		case 1:
		{
			Gender = inputChar("Please give the Gender of your Character. (m,w,d)");
		}
		case 2:
		{
			Height = inputValue("Please enter the Height of your Character. (in cm)");
		}

		case 3:
		{
			Birthdate = inputDate("Please enter the Birthdate of your Character. (xx.xx.xxxx)");
		}

		case 4:
		{
			Inventory = *manager::createNewInventory(&Inventory, *pPlayerCharacter, Name + "'sInventory");
		}
		default:
			break;
		}
		manager::createNewPerson(pPlayerCharacter, Name, Gender, Height, Birthdate, Inventory);
		return true;
	}
}