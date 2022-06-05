#pragma once
#include <iostream>
#include <string>
#include <cctype>


#include "Inventory.h"
#include "Object.h"
#include "decisionInput.h"
#include "date.h"
#include "person.h"

using std::cout; using std::endl;

namespace decision
{
	bool takeObject(Object &pObjToBeTaken, person pWhoTakesIt)
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
				return true;
			}
	}
}