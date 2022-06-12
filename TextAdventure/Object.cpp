#include "Object.h"

Object::Object(string p_name, std::unordered_map<int, bool> *pAllObjectsMap, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID)
{
	object_name = p_name, weight = p_weight, width = p_width, height = p_height, length = p_length;
	unique_id = createUniqueID(p_name, pAllObjectsMap, p_weight * 100, p_width * 10, p_height * 1, p_length * 10000);
	pAllObjectsMap->insert({ unique_id, true }); //adds unique id to global item map
}

int Object::createUniqueID (string p_object_name, std::unordered_map<int, bool> *pAllObjectsMap, double p_weight, double p_width, double p_height, double p_length) {
	int id = 0;
	for ( char c : p_object_name )
	{
		id += int (c);
	}
	id += p_weight + p_width + p_height + p_length;
	int collisioncounter = 0;
	while (!(pAllObjectsMap->find(id) == pAllObjectsMap->end())) //while unique id is present in global id map
	{
		id += (id % 10000 + collisioncounter*collisioncounter);
	}

	return id;
}



