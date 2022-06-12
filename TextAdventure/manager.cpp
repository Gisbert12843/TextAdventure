#include "manager.h"

namespace manager
{

	Person **createNewPerson(Person **pNewPerson, string pName, char pGender, double pHeight, string pBirthdate, Inventory *pInventory)
	{
		if (!pInventory)
		{
			Inventory *newInventory = pInventory;
			pInventory = *createNewInventory(&newInventory, *pNewPerson, pName + "'sInventory");
		}
		*pNewPerson = new Person(pName, pGender, pHeight, pBirthdate, pInventory);
		pInventory->setOwner(*pNewPerson);
		return pNewPerson;
	}

	void killPerson(Person &pSoonDeadPerson)
	{
		delete &pSoonDeadPerson;
	}


	Inventory **createNewInventory(Inventory **pNewInventory, Person *p_owner, string p_name, int p_max_size)
	{
		*pNewInventory = new Inventory(p_owner, p_name, p_max_size);
		return pNewInventory;
	}

	Object **createNewObject(Object **pNewObject, std::unordered_map<int, bool> *pAllMap, string p_name, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID)
	{
		*pNewObject = new Object(p_name,pAllMap, p_weight, p_width, p_height, p_length);
		
		return pNewObject;
	}

	void printInventory(Person pPerson)
	{
		pPerson.getInventory()->printInventory();
	}

	string chooseRarity()
	{
		int wooden_chance = 60, metallic_chance = 30, steel_chance = 10;
		int sum_chances = wooden_chance+metallic_chance+steel_chance;
		auto picked = Random::get(0, sum_chances);

		if (picked < wooden_chance)
		{
			return "wooden";
		}
		else if (picked < wooden_chance+metallic_chance)
		{
			return "metallic";
		}
		else
			return "steel";
	}

	/*template<typename Numeric, typename Generator = std::mt19937>
	Numeric random(Numeric from, Numeric to)
	{
		thread_local static Generator gen(std::random_device{}());

		using dist_type = typename std::conditional
			<
			std::is_integral<Numeric>::value
			, std::uniform_int_distribution<Numeric>
			, std::uniform_real_distribution<Numeric>
			>::type;

		thread_local static dist_type dist;

		return dist(gen, typename dist_type::param_type{ from, to });
	}*/

	double random(double from, double to)
	{
		double returnvalue;
		std::srand(std::time(nullptr));
		returnvalue = double(from + (double)(rand()) / ((double)(RAND_MAX / (to - from))));
		return returnvalue;
	}
	
}