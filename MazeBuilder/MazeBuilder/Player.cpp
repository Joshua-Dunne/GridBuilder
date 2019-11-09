#include "Player.h"

Player::Player() 
	: m_xPos{9}
	, m_yPos{0}
{
}

Player::Player(int t_x, int t_y) 
	: m_xPos{ t_x }
	, m_yPos{ t_y }
{
}
