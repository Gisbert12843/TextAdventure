#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#include "Inventory.h"
#include "Object.h"
#include "decisionInput.h"
#include "date.h"
#include "Person.h"

using std::string;

using std::cout; using std::endl;

namespace decision
{
	
	bool takeObject(Object pObjToBeTaken, Person pWhoTakesIt);

	string inputName(string displaytext);
	int inputValue(string displaytext);
	char inputChar(string displaytext);

	bool createPlayerCharacter(Person **pPlayerCharacter);
	
}