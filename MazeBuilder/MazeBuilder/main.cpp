#include <iostream>
#include "Field.h"

/// <summary>
/// Grid Builder
/// ---------------
/// This project builds a simple 2D Array, and displays the contents as a Field.
/// The Player within this Field can move around the field, and the Window will clear and rebuild the Field to reflect this.
/// This was originally going to be a Maze Builder but I decided to make it a Grid Builder instead.
/// ---------------
/// 
/// Joshua Dunne
/// 9/11/19
/// Time Taken: ~2 hours
/// </summary>

int main()
{
	Field game;
	int direction = 0;

	system("CLS");

	while (true)
	{
		game.generateGrid();

		std::cout << std::endl;

		std::cout << "Gold: ";
		game.displayPlayerGold();
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

		system("CLS");

		game.checkCollision(direction);
		game.movePlayer(direction);
		
	}
	
	std::cout << std::endl;

	system("Pause");
	return 0;
}