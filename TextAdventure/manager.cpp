#include "manager.h"

namespace manager
{
	Person ** createNewPerson(Person **pNewPerson, string pName, char pGender, double pHeight, string pBirthdate , Inventory *pInventory)
	{
		if ( !pInventory )
		{
			Inventory *newInventory = pInventory;
			pInventory = *createNewInventory(&newInventory,*pNewPerson, pName + "'sInventory");
		}
		*pNewPerson = new Person(pName, pGender, pHeight, pBirthdate, pInventory);
		pInventory->setOwner(*pNewPerson);
		return pNewPerson;
	}

	Inventory **createNewInventory(Inventory **pNewInventory, Person *p_owner, string p_name, int p_max_size)
	{
		*pNewInventory = new Inventory(p_owner,p_name,p_max_size);
		return pNewInventory;
	}

	Object **createNewObject(Object **pNewObject, string p_name, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID)
	{
		*pNewObject = new Object(p_name, p_weight, p_width, p_height, p_length);
		return pNewObject;
	}
}