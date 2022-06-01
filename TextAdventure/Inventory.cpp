#include "Inventory.h"
#include <vector>

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

bool Inventory::removeItemFromInventory(Object* p_Object_to_be_removed)
{
	for (int i = 0; i < this->current_size; i++)
	{
		if (inventoryvector.at(i) == p_Object_to_be_removed)
			inventoryvector.erase(inventoryvector.begin()+i);
	}
		return true;

}
