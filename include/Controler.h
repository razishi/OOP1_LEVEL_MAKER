#pragma once

#include"Board.h"

class Controller {
public:
	Controller();
	void run();

private:
	Board m_board;
	sf::Sprite m_background;
};