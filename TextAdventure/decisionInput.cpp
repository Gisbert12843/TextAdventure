#include "decisionInput.h"
namespace decisionInput
{
	bool takeObject(Object &pObjToBeTaken, Person &pWhoTakesIt)
	{

		cout << "Yes = y | No = n" << endl;
		string decision = "";
		do //String Input ErrorHandling
		{

			cin >> decision;
			if (decision != "y" && decision != "n")
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.clear(); cin.sync();
			}
			std::transform(decision.begin(), decision.end(), decision.begin(),
				[](unsigned char c) { return std::tolower(c); });
		} while (decision != "y" && decision != "n");


		if (decision == "n" || decision == "no")
		{
			cout << "You are not taking the " << pObjToBeTaken.getName() << "." << endl;
			return false;
		}
		else
			if (decision == "y" || decision == "yes")
			{
				cout << "You are taking the " << pObjToBeTaken.getName() << "." << endl;

				if (!pWhoTakesIt.getInventory()->addNewItemToInventory(&pObjToBeTaken))
				{
					cout << "The Inventory of " << pWhoTakesIt.getName() << " is full.";
					return false;
				}
				pObjToBeTaken.setLocation(pWhoTakesIt.getInventory());

				return true;
			}
	}

	bool removeObject(Object &pObjToBeRemoved, Person &pWhoRemovesIt)
	{
		cout << "Yes = y | No = n" << endl;
		string decision = "";

		do //String Input ErrorHandling
		{

			cin >> decision;
			if (decision != "y" && decision != "n")
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.clear(); cin.sync();
			}
			std::transform(decision.begin(), decision.end(), decision.begin(),
				[](unsigned char c) { return std::tolower(c); });
		} while (decision != "y" && decision != "n");


		if (decision == "n" || decision == "no")
		{

		}
		else
			if (decision == "y" || decision == "yes")
			{


				return true;
			}
	}


	string inputName(string displaytext)
	{
		string input = "";
		cout << displaytext << endl;
		cin.clear(); cin.sync();
		std::getline(std::cin, input);
		while (!std::all_of(input.begin(), input.end(), ::isalpha))
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
		while (std::all_of(input.begin(), input.end(), ::isalpha))
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
		while (input.empty() && std::find_if(input.begin(),
			input.end(), [](char c) { return !(std::isdigit(c) || c == '.');  }) == input.end()) //This validates a string as a working double
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
		while (!(input == 'm' || input == 'w' || input == 'd'))
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

		switch (mode)
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


	Object *craftObject(string craftedObject = "")
	{
		//if (craftedObject == "")
		//{
		//	cout << endl << "What do you want to craft?" << endl;
		//	cout << "{Knife, Baseballbat}";
		//	do //String Input ErrorHandling
		//	{

		//		cin >> craftedObject;
		//		if (craftedObject != "Knife" && craftedObject != "Baseballbat")
		//		{
		//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//			cin.clear(); cin.sync();
		//		}
		//		std::transform(craftedObject.begin(), craftedObject.end(), craftedObject.begin(),
		//			[](unsigned char c) { return std::tolower(c); });
		//	} while (craftedObject != "Knife" && craftedObject != "Baseballbat");
		//}

		Object *newObject;

		string chosenrarity = manager::chooseRarity();
		string name; double weight=0; double width=0; double height = 0; double length=0;


		if (chosenrarity == "wooden")
		{
			name = "wooden-" + craftedObject;
			weight = manager::random(0.08, 0.25);
			width = manager::random(2.5, 4.0);
			height = manager::random(2.5, 4.0);
			length = manager::random(12, 18);
		}
		else
			if (chosenrarity == "metallic")
			{
				name = "metallic-" + craftedObject;
				weight = manager::random(0.4, 1.0);
				width = manager::random(3.0, 5.0);
				height = manager::random(3.0, 5.0);
				length = manager::random(15, 23);
			}
			else
			{
				name = "steel-" + craftedObject;
				weight = manager::random(0.8, 1.5);
				width = manager::random(3.5, 5.5);
				height = manager::random(3.5, 5.5);
				length = manager::random(18, 30);
			}
		cout << "Crafting a " << name << "." << endl;
		manager::createNewObject(&newObject, name, weight, width, height, length);
		return newObject;
	}


	//end of namespace
}