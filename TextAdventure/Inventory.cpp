#include "Inventory.h"
#include <vector>

Inventory::Inventory(Person *p_owner, string p_name, int p_max_size)
{
	name = p_name, max_size = p_max_size, owner = p_owner;
}

bool Inventory::addNewItemToInventory(Object *p_addedObject) {
	if (current_size == max_size)
		return false;
	else
	{
		inventory_map[p_addedObject->getUniqueID()] = p_addedObject;
		p_addedObject->setLocation(this);
		this->current_size++;
		return true;
	}
}

bool Inventory::removeItemFromInventory(Object *p_removedObject) {
	if (this->inventory_map.erase(p_removedObject->getUniqueID()))
	{
		p_removedObject->setLocation(nullptr);
		return true;
	}
	else
	{
		return false;
	}//THIS STILL NEEDS A NEW LOCATION TO RELOCATE THE DROPPED OBJECT
}

bool Inventory::hasItem(Object *p_searchedObject) {
	if (inventory_map.count(p_searchedObject->getUniqueID()) != false)
		return true;
	else
		return false;
}

void Inventory::printInventory()
{
	std::unordered_map<int, Object *> const &m = this->inventory_map;
	int i = 0;
	std::cout << std::endl;
	for (auto const &pair : this->inventory_map) {
		std::cout << "{" << pair.first << ": " << pair.second->getName() << "}";
		i++;
		if (i == 3)
		{
			std::cout << std::endl;
			i = 0;
			continue;
		}
		if (i > 1)
			std::cout << "\t";

	}
}
