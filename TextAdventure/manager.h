#pragma once
#include "Object.h"
#include "Inventory.h"
#include "date.h"
#include "Person.h"
#include "decisionInput.h"

namespace manager
{
	Person **createNewPerson(Person **pNewPerson, string pName = "", char pGender = 'n', double pHeight = 0, string pBirthdate = "1.1.1", Inventory *pInventory = nullptr);

	Inventory **createNewInventory(Inventory **pNewInventory, Person *p_owner = nullptr, string p_name = "", int p_max_size = 100);

	

}