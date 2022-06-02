#pragma once
#include "Inventory.h"
#include <string>
#include <algorithm>

class Inventory;

class Object {								//Generic Object Declaration
private:
	std::string object_name;
	int unique_id;
	double weight;
	double width;
	double height;
	double length;
	Inventory* located_in = nullptr;		//The Container the Object is located in

	int createUniqueID(std::string p_object_name, double p_weight, double p_width, double p_height, double p_length);

public:
	std::string getName() {
		return object_name;
	}
	int getUniqueID() {
		return unique_id;
	}
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
	Object(std::string p_name = "", double p_weight = 0, double p_width = 0, double p_height = 0, double p_length = 0, int p_uniqueID = NULL);

};