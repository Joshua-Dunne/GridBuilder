#include "Player.h"

/// <summary>
/// Default constructor for player. Sets positions to {9,0} with 0 Gold
/// </summary>
Player::Player() 
	: m_xPos{9}
	, m_yPos{0}
	, m_gold{0}
{
}

/// <summary>
/// Overloaded constructor that lets you place the player
/// </summary>
/// <param name="t_x">X Position</param>
/// <param name="t_y">Y Position</param>
Player::Player(int t_x, int t_y) 
	: m_xPos{ t_x }
	, m_yPos{ t_y }
	, m_gold{ 0 }
{
}
