#pragma once

#include "Player.h"
#include <iostream>

class Field
{
public:
	Field();

	static const int MAX_WIDTH{ 10 }; // width of grid
	static const int MAX_HEIGHT{ 10 }; // height of grid

	enum class Direction { NONE, NORTH, SOUTH, EAST, WEST }; // direction movement

private:
	void fillGrid(); // fills grid with necessary information

	Direction m_direction{ Direction::NORTH }; // the way the player is moving

	char GameGrid[MAX_WIDTH][MAX_HEIGHT]; // the field

	Player m_player{ 9,0 }; // our player

	int m_chestPos[2]{ 5,5 }; // where the chest is

public:
	
	void generateGrid();
	void movePlayer(int t_direction);
	void checkCollision(int t_direction);
	void inline displayPlayerGold() const { std::cout << m_player.getGold(); };
};

