#include "Object.h"

int Object::createUniqueID (string p_object_name, double p_weight, double p_width, double p_height, double p_length) {
	int id = 0;
	for ( char c : p_object_name )
	{
		id += int (c);
	}
	return (id + p_weight + p_width + p_height + p_length);
}

Object::Object (string p_name, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID) {
	object_name = p_name, weight = p_weight, width = p_width, height = p_height, length = p_length;
	unique_id = createUniqueID (p_name, p_weight * 100, p_width * 100, p_height * 100, p_length * 100);
}

