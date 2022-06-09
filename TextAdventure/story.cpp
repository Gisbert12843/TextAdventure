#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "story.h"
#include "Inventory.h"
#include "Object.h"
#include "decisionInput.h"
#include "manager.h"

#define sleep Sleep(100);
#define text(a) std::cout << a;  std::cin.get();sleep

bool greenforest()
{
	system("cls");
	std::cin.ignore();
	Person *playerCharacter =nullptr;
	decisionInput::createPlayerCharacter(&playerCharacter);
	text("You see nothing but white when you first wake up.");
	text("It seems to be the first sunlight of the day, flooding your eyes.");
	text("It seems they haven't seen much other than darkness for quite some time.");
	text("You are now able to see something.");
	text("You see grass. It seems that you are lying in the glade of a forest.");
	text("Not a single memory of how you got here comes to your mind.");
	text("You don't seem hurt. Atleast you don't feel any pain at the moment.");
	text("As you take a quick look around, you see something shiny sticking in the dirt right there at your feet.");
	text("It appears to be a knife. Not in the best condition, but it feels somewhat sturdy.");
	text("Are you taking the Knife with you?");

	text("You grab the knife thats laying on the floor and put it into you backpack.");



	return true;
}