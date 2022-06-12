#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "story.h"
//#include "Inventory.h"
#include "Object.h"
#include "decisionInput.h"
#include "manager.h"




#define waitingDots sleep500; cout << "."; sleep1000; cout << "."; sleep1000; cout << "."; sleep1000 cout << endl;

#define sleep100 Sleep(100);
#define sleep300 Sleep(300);
#define sleep500 Sleep(500);
#define sleep1000 Sleep(1000);
#define text(a) std::cout << a; std::cin.get();sleep500
#define craft(a) decisionInput::craftObject(a, AllObjectsMap)
#define addItem(person, item) 	person->getInventory()->addNewItemToInventory(item)


bool greenforest()
{
	system("cls");
	std::cin.ignore();
	std::unordered_map<int, bool> *AllObjectsMap = new std::unordered_map<int, bool>();
	Person* playerCharacter = nullptr;
	Person* testPerson = nullptr;
	manager::createNewPerson(&testPerson, "Karl", 'm', 182, "1.1.2000");
	//decisionInput::createPlayerCharacter(&testPerson);

	system("cls");
	/*waitingDots;
	text("You see nothing but white when you first wake up.");
	text("It seems to be the first sunlight of the day, flooding your eyes.");
	text("It seems they haven't seen much other than darkness for quite some time.");
	text("You are now able to see something.");
	text("You see grass. It seems that you are lying in the glade of a forest.");
	text("Not a single memory of how you got here comes to your mind.");
	text("You don't seem hurt. Atleast you don't feel any pain at the moment.");
	text("As you take a quick look around, you see something shiny sticking in the dirt right there at your feet.");
	text("It appears to be a knife. Not in the best condition, but it feels somewhat sturdy.");
	text("Are you taking the Knife with you?");*/
	Object* woodenKnife;
	manager::createNewObject(&woodenKnife, AllObjectsMap, "WoodenKnife", 0.3, 6, 5, 16);
	if (decisionInput::takeObject(*woodenKnife, *testPerson))
	{
		text("You grab the knife thats laying on the floor and put it into you backpack.");
	}
	else
	{
		text("It doesn't feel right to you. You precede, leaving the knife stuck in the mud.")
	}



	Object* baseballbatt1 = decisionInput::craftObject("baseballbat", AllObjectsMap);
	testPerson->getInventory()->addNewItemToInventory(baseballbatt1);

	Object* baseballbatt2 = decisionInput::craftObject("baseballbat", AllObjectsMap);
	testPerson->getInventory()->addNewItemToInventory(baseballbatt2);

	Object* baseballbatt3 = decisionInput::craftObject("baseballbat", AllObjectsMap);
	testPerson->getInventory()->addNewItemToInventory(baseballbatt3);

	//Object* baseballbatt4 = craft("baseballbat");
	//addItem(testPerson, baseballbatt4);

	//Object* baseballbatt5 = craft("baseballbat");
	//addItem(testPerson, baseballbatt5);

	//Object* baseballbatt6 = craft("baseballbat");
	//addItem(testPerson, baseballbatt6);

	//Object* baseballbatt7 = craft("baseballbat");
	//addItem(testPerson, baseballbatt7);

	//Object* baseballbatt8 = craft("baseballbat");
	//addItem(testPerson, baseballbatt8);

	for (int i = 0; i < 10; i++)
	{
		Object* baseballbatt = craft("baseballbat");
		addItem(testPerson, baseballbatt);

	}

	manager::printInventory(*testPerson);


	cin.ignore();
	return true;
}