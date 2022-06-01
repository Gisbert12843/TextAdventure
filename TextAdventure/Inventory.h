#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Object.h"
#include <string>

class Object;
class Inventory {							//High_Level, summary of Inventory Items in a given Inventory-Object able to store things.
private:
	std::string name ="";					//Name of the inventory
	std::vector<Object*>inventoryvector;	//The Inventory based on a Vector of Pointers to Objects of the 'Object-Class'
	int max_size;							//Maximum Size of this inventory
	int current_size=0;						//Current amount of Objects stored in this Inventory

public:
	Inventory(std::string p_name,int p_max_size) { name = p_name, max_size = p_max_size; }
	bool addNewItemToInventory(Object* p_Object_to_be_added);
	bool removeItemFromInventory(Object* p_Object_to_be_removed);
};