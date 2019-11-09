#pragma once

#include "Player.h"
#include <iostream>

class Field
{
public:
	Field();

	static const int MAX_WIDTH{ 10 };
	static const int MAX_HEIGHT{ 10 };

	enum class Direction { NONE, NORTH, SOUTH, EAST, WEST };

private:
	void fillGrid();

	Direction m_direction{ Direction::NORTH };

	char GameGrid[MAX_WIDTH][MAX_HEIGHT];
	Player m_player{ 9,0 };

public:
	
	void generateGrid();
	void movePlayer(int t_direction);
};

