#include "Inventory.h"
#include <vector>

bool Inventory::addNewItemToInventory (Object *p_addedObject) {
	if ( current_size = max_size )
		return false;
	else
	{
		inventory_map[p_addedObject->getUniqueID ()] = p_addedObject;
		p_addedObject->setLocation (this);
		return true;
	}
}

bool Inventory::removeItemFromInventory (Object *p_removedObject) {
	if ( this->inventory_map.erase (p_removedObject->getUniqueID ()) )
		return true;
	else
		return false;
	//THIS STILL NEEDS A NEW LOCATION TO RELOCATE THE DROPPED OBJECT
}

bool Inventory::hasItem (Object *p_searchedObject) {
	if ( inventory_map.count (p_searchedObject->getUniqueID ()) != false )
		return true;
	else
		return false;
}
