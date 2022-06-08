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

using std::cout; using std::endl;



int main()
{
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
			//Test for Date Functions
			cout << "\nStart Date Function Test" << endl;
			date test1 = getCurrentDate();
			string test2(getDateAsString(test1));
			date test3(getDateAsDateObj(test2));
			cout << getDateAsString(test3) << endl;

			//Test for Object Functions
			cout << "\nStart Object Function Test" << endl;

			Object testObject("WoodenKnife", 0.5, 5, 3, 18);
			cout << testObject.getName() << endl;
			cout << testObject.getUniqueID() << endl;
			cout << testObject.getWeight() << endl;
			cout << testObject.getWidth() << endl;
			cout << testObject.getHeight() << endl;
			cout << testObject.getLength() << endl;

			

			//Test for Person Functions
			cout << "\nStart Person Function Test" << endl;
			Person testPerson("Karl", 'm', 182, "1.1.2000");
			cout << "Karl, 'm', 182, 1.1.2000" << endl;
			cout << testPerson.getName() << endl;
			cout << testPerson.getGender() << endl;
			cout << testPerson.getHeight() << endl;
			cout << testPerson.getBirthdate() << endl;
			cout << testPerson.getCurrentAge(getDateAsDateObj(testPerson.getBirthdate())) << endl;

			//Test for Inventory Functions
			cout << "\nStart Inventory Function Test" << endl;
			//Person testPerson("Heinz", 'm', 181, "1.1.2001");
			Inventory testInventory(&testPerson, "aTestInventory");
			cout << "aTestInventory, 100, 0, Karl" << endl;
			cout << testInventory.getName() << endl;
			cout << testInventory.getMaxSize() << endl;
			cout << testInventory.getCurrentSize() << endl;
			cout << testInventory.getOwner()->getName() << endl;


			testInventory.addNewItemToInventory(&testObject);
			if ( testInventory.hasItem(&testObject) && testObject.getLocation() == &testInventory )
				cout << "Has Object!" << endl;
			else
			{
				cout << "Doesn't have Object :(" << endl;
			}
			//Test for Decision Functions
			cout << "\nStart Decision Function Test" << endl;

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