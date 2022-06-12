#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "Object.h"
#include "Inventory.h"
#include "story.h"
#include "date.h"
#include "Person.h"
#include "decisionInput.h"

using std::cout; using std::endl;


#define craft(a) decisionInput::craftObject(a, AllObjectsMap)
#define addItem(person, item) 	person->getInventory()->addNewItemToInventory(item)


int main()
{
	srand(time(NULL));

	cout << "Welcome to this awesome Text Adventure\n" << endl;
	while ( true )
	{

		cout << "\n\nChoose a Mode please!" << endl;
		cout << "1: Start in a green forest.\n2: Function Tests.\n3: EXIT" << endl;


		unsigned mode = 0;
		std::cin >> mode;
		switch ( mode )
		{
		case 1:
		{
			if ( greenforest() )
				cout << "\n***Congrats, you have beaten the Green Forest!!***\n" << endl;
			else
				cout << "\n***Sadly the Green Forest got you good. :(" << endl;
			break;


		}
		case 2:
		{
			std::unordered_map<int, bool>* AllObjectsMap = new std::unordered_map<int, bool>();

			//Test for Date Functions
			cout << "\n\nStart Date Function Test" << endl;
			cout << "Today is: ";
			date test1 = getCurrentDate();
			string test2(getDateAsString(test1));
			date test3(getDateAsDateObj(test2));
			cout << getDateAsString(test3) << endl;



			//Test for Object Functions
			cout << "\n\nStart Object Function Test" << endl;
			Object testObject("WoodenKnife",AllObjectsMap,  0.5, 5, 3, 18);
			cout << testObject.getName() << endl;
			cout << testObject.getUniqueID() << endl;
			cout << testObject.getWeight() << endl;
			cout << testObject.getWidth() << endl;
			cout << testObject.getHeight() << endl;
			cout << testObject.getLength() << endl;

			

			//Test for Person Functions
			cout << "\n\nStart Person Function Test" << endl;
			Person *testPerson = new Person("Karl", 'm', 182, "1.1.2000");
			cout << "Karl, 'm', 182, 1.1.2000" << endl;
			cout << testPerson->getName() << ", ";
			cout << testPerson->getGender() << ", ";
			cout << testPerson->getHeight() << ", ";
			cout << testPerson->getBirthdate() << ", ";
			cout << testPerson->getCurrentAge(getDateAsDateObj(testPerson->getBirthdate())) << endl;

			Object* baseballbatt1 = decisionInput::craftObject("baseballbat", AllObjectsMap);
			testPerson->getInventory()->addNewItemToInventory(baseballbatt1);

			Object* baseballbatt2 = decisionInput::craftObject("baseballbat", AllObjectsMap);
			testPerson->getInventory()->addNewItemToInventory(baseballbatt2);

			Object* baseballbatt3 = decisionInput::craftObject("baseballbat", AllObjectsMap);
			testPerson->getInventory()->addNewItemToInventory(baseballbatt3);

			Object* baseballbatt4 = craft("baseballbat");
			addItem(testPerson, baseballbatt4);



			//Test for Inventory Functions
			cout << "\n\nStart Inventory Function Test" << endl;
			Inventory testInventory(testPerson, "aTestInventory");
			cout << "aTestInventory, 100, 0, Karl" << endl;
			cout << testInventory.getName() << ", ";
			cout << testInventory.getMaxSize() << ", ";
			cout << testInventory.getCurrentSize() << ", ";
			cout << testInventory.getOwner()->getName() << endl;
			testInventory.addNewItemToInventory(&testObject);
			if ( testInventory.hasItem(&testObject) && testObject.getLocation() == &testInventory )
				cout << "Has Object!" << endl;
			else
				cout << "Doesn't have Object :(" << endl;



			//Test for Decision Functions
			cout << "\nStart Decision Function Test" << endl;
			char testChar = 'm';
			char compareChar;
			compareChar = decisionInput::inputChar("Please input a 'm'.");
			if ( testChar == compareChar )
				cout << "decision worked!" << endl;
			else cout << "decision didnt work." << endl;

			//Test for Manager Functions
			cout << "\nStart Manager Function Test" << endl;
			cout << manager::random(1, 2) << endl;
			for(int i = 0; i < 20; i++)
			cout << manager::chooseRarity() << endl;


			continue;
		}
		case 3:
		{
			return 0;
		}
		default:
			break;
		}
		break;
	}




	system("Pause");
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 0;

}