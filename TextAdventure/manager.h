#pragma once
#include "Object.h"
#include "Inventory.h"
#include "date.h"
#include "Person.h"
//#include "decisionInput.h"
#include <random>


namespace manager
{
	Person **createNewPerson(Person **pNewPerson, string pName = "", char pGender = 'n', double pHeight = 0, string pBirthdate = "1.1.1", Inventory *pInventory = nullptr);

	Inventory **createNewInventory(Inventory **pNewInventory, Person *p_owner = nullptr, string p_name = "", int p_max_size = 100);

	Object **createNewObject(Object **pNewObject, string p_name, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID=0);

	void killPerson(Person &pSoonDeadPerson);

	void printInventory(Person &pPerson);

	string chooseRarity();

	double random(double from, double to);

}