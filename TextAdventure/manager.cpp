#include "manager.h"

namespace manager
{
	Person ** createNewPerson(Person **pNewPerson, string pName, char pGender, double pHeight, string pBirthdate , Inventory *pInventory)
	{
		*pNewPerson = new Person(pName, pGender, pHeight, pBirthdate, pInventory);
		return pNewPerson;
	}

	Inventory **createNewInventory(Inventory **pNewInventory, Person *p_owner, string p_name, int p_max_size)
	{
		*pNewInventory = new Inventory(p_owner,p_name,p_max_size);
		return pNewInventory;
	}

}