#pragma once
struct Player
{
	Player();
	Player(int t_x, int t_y);

	int m_xPos;
	int m_yPos;

	void inline setPosition(int t_xPos, int t_yPos) { m_xPos = t_xPos; m_yPos = t_yPos; };
	int getXPos() const { return m_xPos; };
	int getYPos() const { return m_yPos; };
};

