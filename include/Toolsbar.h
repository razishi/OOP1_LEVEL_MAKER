#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

const int iconSize = 10;
const int ICON_SIZE_PIC = 50;
const int SIZEOFIMGS = 800 / iconSize;
const int SIZEOFREC = (ICON_SIZE_PIC * 2);

enum Characters {
    Mouse, Cat, WALL, DOOR, KEY, Cheese, GIFT, DELETE, DELETEALL, SAVE, NONE
};

class Toolsbar {
public:
    Toolsbar();
    void buildToolsbar();
    void drawIcon(sf::RenderWindow&);
    int findCharacter(sf::Vector2f)const;
    sf::Sprite getspirt(int);


private:
    sf::RectangleShape m_Toolsbar;
    sf::Vector2f m_location_icon[iconSize];
    sf::Texture m_textpicture[iconSize];
    sf::Sprite m_pictures[iconSize];
};


