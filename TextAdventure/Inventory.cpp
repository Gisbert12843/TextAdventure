#include "Inventory.h"

bool Inventory::addNewItemToInventory(Object* p_Object_to_be_added)
{
	if (current_size = max_size)
		return false;
	else
	{
		inventoryvector.push_back(p_Object_to_be_added);
		p_Object_to_be_added->setLocation(this);
		return true;
	}
}
