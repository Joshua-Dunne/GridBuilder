#pragma once

struct Player
{
	Player();
	Player(int t_x, int t_y);

	int m_xPos; // where the player is on the grid (X)
	int m_yPos; // where the player is on the grid (Y)
	int m_gold; // player's gold count

	void inline setPosition(int t_xPos, int t_yPos) { m_xPos = t_xPos; m_yPos = t_yPos; }; // set position of player
	void inline addGold(int t_amount) { m_gold += t_amount; }; // add into gold amount when touching a chest
	int getXPos() const { return m_xPos; };
	int getYPos() const { return m_yPos; };
	int getGold() const { return m_gold; };
};

