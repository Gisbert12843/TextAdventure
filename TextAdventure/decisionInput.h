#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <unordered_map>
#include <string>
#include <sstream>

#include "Inventory.h"
#include "Object.h"
#include "date.h"
#include "Person.h"
#include "manager.h"

using std::string;

using std::cout; using std::endl; using std::cin;

namespace decisionInput
{

	bool takeObject(Object &pObjToBeTaken, Person &pWhoTakesIt);
	bool removeObject(Object &pObjToBeRemoved, Person &pWhoRemovesIt);

	string inputName(string displaytext);
	string inputDate(string displaytext);
	double inputValue(string displaytext);
	char inputChar(string displaytext);

	bool createPlayerCharacter(Person **pPlayerCharacter);

	Object *craftObject(string craftedObject, std::unordered_map<int, bool> *pAllObjectsMap);
}