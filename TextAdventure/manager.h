#pragma once
#include "Object.h"
#include "Inventory.h"
#include "date.h"
#include "Person.h"
#include "decisionInput.h"

namespace manager
{
	bool createNewPerson(Person **pNewPerson, string pName = "", char pGender = 'n', double pHeight = 0, string pBirthdate = "1.1.1", Inventory *pInventory = nullptr)
	{
		*pNewPerson = new Person(pName, pGender, pHeight, pBirthdate, pInventory);
		return true;
	}


	

}