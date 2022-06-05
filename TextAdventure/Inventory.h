#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Object.h"
#include <string>
#include <unordered_map>

class Object;
class Inventory {											//High_Level summary of Inventory Items
private:
	std::string name ="";									//Name of the inventory
	std::unordered_map<int, Object *> inventory_map;	    //The Inventory based on a hashmap of Pointers to Objects of the 'Object-Class'
	int max_size;											//Maximum Size of this inventory
	int current_size=0;										//Current amount of Objects stored in this Inventory

public:
	
	Inventory(std::string p_name,int p_max_size) { name = p_name, max_size = p_max_size; }
	bool addNewItemToInventory(Object* p_addedObject);
	bool removeItemFromInventory(Object* p_removedObject);
	bool hasItem(Object* p_searchedObject);
};