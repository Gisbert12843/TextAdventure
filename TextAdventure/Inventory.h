#pragma once
#include <iostream>
#include <vector>
#include <sstream>
	//template <class TObject>

class Inventory;
class Object {								//Generic Object Declaration
private:
	double weight;
	double width;
	double height;
	double length;
	Inventory* located_in = nullptr;		//The Container the Object is located in

public:
	bool getWeight() {
		return weight;
	}
	bool getWidth() {
		return width;
	}
	bool getHeight() {
		return height;
	}
	bool getLength() {
		return length;
	}
	bool setLocation(Inventory* p_new_Location)
	{
		located_in = p_new_Location;
		return 0;
	}
	Object(double p_weight = 0, double p_width = 0, double p_height = 0, double p_length = 0) { //Creating of an Object
		weight = p_weight, width = p_width, height = p_height, length = p_length;
	}

};

class Inventory {							//High_Level, summary of Inventory Items in a given Inventory-Object able to store things.
private:
	std::vector<Object*>inventoryvector;	//The Inventory based on a Vector of Pointers to Objects of the 'Object-Class'
	int max_size;							//Maximum Size of this inventory
	int current_size=0;						//Current amount of Objects stored in this Inventory

public:
	Inventory(int p_max_size) { max_size = p_max_size; }
	bool addNewItemToInventory(Object* p_Object_to_be_added);
};