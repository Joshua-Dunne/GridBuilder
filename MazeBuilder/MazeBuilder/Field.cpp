#include "Field.h"

/// <summary>
/// Default constructor for Field
/// </summary>
Field::Field()
{
	fillGrid();
}

/// <summary>
/// Fills the Grid with necessary information.
/// </summary>
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

	GameGrid[m_chestPos[0]][m_chestPos[1]] = 'C';
}

/// <summary>
/// Displays the Grid in the Console window
/// </summary>
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

/// <summary>
///  Move the Player via the 2D array.
/// </summary>
/// <param name="t_direction">Direction to move the Player</param>
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

/// <summary>
/// Check for Collisions between Player and Chest.
/// Repeat this for any other collisions.
/// </summary>
/// <param name="t_direction">Direction Player is moving towards</param>
void Field::checkCollision(int t_direction)
{
	if (t_direction == static_cast<int>(Direction::NORTH))
	{
		if (m_player.getXPos() == m_chestPos[0] && m_player.getYPos() == m_chestPos[1] + 1)
		{
			std::cout << "Walking into Chest from Top\n";
			m_player.addGold(5);
			m_chestPos[0] = -99; // move chest off the grid
			m_chestPos[1] = -99; // move chest off the grid
		}
	}
	else if (t_direction == static_cast<int>(Direction::SOUTH))
	{
		if (m_player.getXPos() == m_chestPos[0] && m_player.getYPos() == m_chestPos[1] - 1)
		{
			std::cout << "Walking into Chest from Bottom\n";
			m_player.addGold(5);
			m_chestPos[0] = -99; // move chest off the grid
			m_chestPos[1] = -99; // move chest off the grid
		}
	}
	else  if (t_direction == static_cast<int>(Direction::EAST))
	{
		if (m_player.getXPos() == m_chestPos[0] - 1 && m_player.getYPos() == m_chestPos[1])
		{
			std::cout << "Walking into Chest from Right\n";
			m_player.addGold(5);
			m_chestPos[0] = -99; // move chest off the grid
			m_chestPos[1] = -99; // move chest off the grid
		}
	}
	else if (t_direction == static_cast<int>(Direction::WEST))
	{
		if (m_player.getXPos() == m_chestPos[0] + 1 && m_player.getYPos() == m_chestPos[1])
		{
			std::cout << "Walking into Chest from Left\n";
			m_player.addGold(5);
			m_chestPos[0] = -99; // move chest off the grid
			m_chestPos[1] = -99; // move chest off the grid
		}
	}
}
