#include "Field.h"

Field::Field()
{
	fillGrid();
}

void Field::fillGrid()
{
	for (int y = 0; y < MAX_WIDTH; ++y)
	{
		for (int x = 0; x < MAX_HEIGHT; ++x)
		{
			if (m_player.getXPos() == x && m_player.getYPos() == y)
			{
				GameGrid[y][x] = 'P';
			}
			else
			{
				GameGrid[y][x] = ' ';
			}
		}

		std::cout << std::endl;
	}

	GameGrid[5][5] = 'C';
}

void Field::generateGrid()
{
	for (int y = 0; y < MAX_WIDTH; ++y)
	{
		std::cout << "|";
		for (int x = 0; x < MAX_HEIGHT; ++x)
		{
			std::cout << "-" << GameGrid[y][x] << "-";
		}

		std::cout << "|" << std::endl;
	}
}

void Field::movePlayer(int t_direction)
{

	if (t_direction == static_cast<int>(Direction::NORTH))
	{
		if (m_player.getYPos() > 0)
		{
			GameGrid[m_player.getYPos()][m_player.getXPos()] = ' '; // set where the player was to empty

			m_player.setPosition(m_player.getXPos(), m_player.getYPos() - 1); // set new position of player

			GameGrid[m_player.getYPos()][m_player.getXPos()] = 'P'; // set where the player is to P
		}
	}
	else if (t_direction == static_cast<int>(Direction::SOUTH))
	{
		if (m_player.getYPos() < MAX_WIDTH - 1)
		{
			GameGrid[m_player.getYPos()][m_player.getXPos()] = ' '; // set where the player was to empty

			m_player.setPosition(m_player.getXPos(), m_player.getYPos() + 1); // set new position of player

			GameGrid[m_player.getYPos()][m_player.getXPos()] = 'P'; // set where the player is to P
		}
	}
	else  if (t_direction == static_cast<int>(Direction::EAST))
	{
		if (m_player.getXPos() < MAX_HEIGHT - 1)
		{
			GameGrid[m_player.getYPos()][m_player.getXPos()] = ' '; // set where the player was to empty

			m_player.setPosition(m_player.getXPos() + 1, m_player.getYPos());; // set new position of player

			GameGrid[m_player.getYPos()][m_player.getXPos()] = 'P'; // set where the player is to P
		}
	}
	else if (t_direction == static_cast<int>(Direction::WEST))
	{
		if (m_player.getXPos() > 0)
		{
			GameGrid[m_player.getYPos()][m_player.getXPos()] = ' '; // set where the player was to empty

			m_player.setPosition(m_player.getXPos() - 1, m_player.getYPos()); // set new position of player

			GameGrid[m_player.getYPos()][m_player.getXPos()] = 'P'; // set where the player is to P
		}
	} 
}
