#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Object.h"
#include <string>
#include <unordered_map>
#include "Person.h"

class Object;
class Person;
class Inventory {											//High_Level summary of Inventory Items
private:
	string name = "";									//Name of the inventory
	std::unordered_map<int, Object *> inventory_map;	    //The Inventory based on a hashmap of Pointers to Objects of the 'Object-Class'
	int max_size;											//Maximum Size of this inventory
	int current_size = 0;										//Current amount of Objects stored in this Inventory
	Person *owner;

public:
	string getName(){ return name; }
	int getMaxSize() { return max_size; }
	int getCurrentSize() { return current_size; }
	Person *getOwner() { return owner; }

	Inventory(Person *p_owner=nullptr, string p_name="", int p_max_size=100)
	{ name = p_name, max_size = p_max_size, owner = p_owner; }
	bool addNewItemToInventory(Object* p_addedObject);
	bool removeItemFromInventory(Object* p_removedObject);
	bool hasItem(Object* p_searchedObject);
};