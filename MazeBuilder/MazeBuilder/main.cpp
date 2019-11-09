#include <iostream>
#include "Field.h"

int main()
{
	Field game;
	int direction = 0;

	system("CLS");

	while (true)
	{
		game.generateGrid();

		std::cout << std::endl;
		std::cout << "Please choose a direction to move.\n";
		std::cout << "1: North\n2: South\n3: East\n4: West\n";
		std::cout << "Alternatively, you can input any other number to QUIT.\n";
		std::cout << "Your choice: ";
		std::cin >> direction;

		if (direction > 4 || direction < 1)
		{
			system("CLS");
			break;
		}

		game.movePlayer(direction);

		system("CLS");
	}
	
	std::cout << std::endl;

	system("Pause");
	return 0;
}