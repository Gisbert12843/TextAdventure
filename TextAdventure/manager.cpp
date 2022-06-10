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

	Object **createNewObject(Object **pNewObject, string p_name, double p_weight, double p_width, double p_height, double p_length, int p_uniqueID)
	{
		*pNewObject = new Object(p_name, p_weight, p_width, p_height, p_length);
		return pNewObject;
	}

	void printInventory(Person &pPerson)
	{
		pPerson.getInventory()->printInventory();
	}

	string chooseRarity()
	{
		int sum_chances = 60 + 30 + 10;
		int picked = rand() % sum_chances;

		if (picked <= 59)
		{
			return "wooden";
		}
		else if (picked <= 89)
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