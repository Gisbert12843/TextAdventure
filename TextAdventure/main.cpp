#include <iostream>
#include "Object.h"
#include "Inventory.h"
#include "story.h"


int main()
{
	std::cout << "Welcome to this awesome Text Adventure\n" << std::endl;
	while (true)
	{

		std::cout << "Choose a Mode please!" << std::endl;
		std::cout << "1: Start in a green forest.\n2: Start in an empty city.\n3: Start on the frontlines." << std::endl;


		unsigned mode = 0;
		std::cin >> mode;
		switch (mode)
		{
		case 1:
		{
			if (greenforest())
				std::cout << "\n***Congrats, you have beaten the Green Forest!!" << std::endl;
			else
				std::cout << "\n***Sadly the Green Forest got you good. :(" << std::endl;
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			break;
		}

	}




	system("Pause");
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return 0;

}