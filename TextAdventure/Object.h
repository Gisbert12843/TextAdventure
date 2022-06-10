#pragma once
#include "Inventory.h"
#include <string>
#include <algorithm>

using std::string;

class Inventory;

class Object {								//Generic Object Declaration
private:
	string object_name = "";
	int unique_id = 0;
	double weight = 0;						//in kg
	double width = 0;						//in cm
	double height = 0;						//in cm
	double length = 0;						//in cm
	Inventory *located_in = nullptr;		//The Container the Object is located in

	int createUniqueID(string p_object_name, double p_weight, double p_width, double p_height, double p_length);

public:
	string getName()
	{
		return object_name;
	}
	int getUniqueID()
	{
		return unique_id;
	}
	double getWeight()
	{
		return weight;
	}
	double getWidth()
	{
		return width;
	}
	double getHeight()
	{
		return height;
	}
	double getLength()
	{
		return length;
	}
	Inventory* getLocation()
	{
		return located_in;
	}
	bool setLocation(Inventory *p_new_Location)
	{
		located_in = p_new_Location;
		return 0;
	}
	Object(string p_name = "", double p_weight = 0, double p_width = 0, double p_height = 0, double p_length = 0, int p_uniqueID = 0);
};