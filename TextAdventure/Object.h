#pragma once
#include "Inventory.h"

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