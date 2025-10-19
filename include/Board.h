#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Toolsbar.h"
#include "Row.h"

using std::cin;
using std::cout;
using std::endl;

const char m_charactersArray[10] = { '%','^','#','D','K','*','$','R','T','S' };

class Board {
public:
	Board();
	void readData();
	void ClickMouse(sf::Event, sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	bool getDeleteMode();
	void setDeletedMode();
	void clearBoard();

private:
	Toolsbar m_Toolsbar;
	sf::Sprite m_movingIcon;
	sf::RectangleShape m_background, m_RectMouseMove;

	unsigned int m_row, m_col;
	int m_xstart, m_ystart, m_selectedIcon;
	bool m_deleteMode, m_MouseInMap;

	void drawRowCols(sf::RenderWindow& window);
	void saveMap();
	void drawPic(sf::RenderWindow& window, char character, sf::Vector2f position);
	void ClickToolbar(sf::Vector2f, sf::Event, sf::RenderWindow&);
	void resetBackground();
	void setBoard();
	int findeindexVector(char)const;

	std::vector<Row> m_board;
};
