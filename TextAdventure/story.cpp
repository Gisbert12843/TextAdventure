#include <iostream>
#include "story.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Inventory.h"
#include "Object.h"

#define sleep Sleep(500);
#define text(a) std::cout << a; std::cin.get();

bool greenforest () {
	system ("cls");
	std::cin.ignore ();

	text ("You see nothing but white when you first wake up.")
	text ("It seems to be the first sunlight of the day, flooding your eyes.")
	text ("It seems they haven't seen much other than darkness for quite some time.")
	text ("You are now able to see something.")
	text ("You grab the knife thats laying on the floor and put it into you backpack.")


		return true;
}