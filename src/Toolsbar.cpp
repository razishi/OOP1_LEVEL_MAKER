#include "Toolsbar.h"
#include <iostream>

Toolsbar::Toolsbar()
{
    buildToolsbar(); // Call function to build the toolbar
}

//-----------------------------------------------------------------------------------------

void Toolsbar::buildToolsbar()
{
    // Calculate the position for each icon in the toolbar
    for (int i = 0; i < iconSize; i++)
        m_location_icon[i] = sf::Vector2f(0, i * (800 / iconSize));

    // Load texture for each icon, scale it, and set its position
    for (int i = 0; i < iconSize; i++) {
        std::string Charcter_name = "Charcter" + std::to_string(i) + ".png"; // Generate file name for each icon
        m_textpicture[i].loadFromFile(Charcter_name); // Load texture from file
        m_pictures[i].setTexture(m_textpicture[i]); // Set texture for sprite
        m_pictures[i].setScale(sf::Vector2f(((800 / iconSize) / m_pictures[i].getGlobalBounds().width),
            (((800 / iconSize) / m_pictures[i].getGlobalBounds().height)))); // Scale the sprite
        m_pictures[i].setPosition(m_location_icon[i].x, m_location_icon[i].y); // Set position for sprite
    }
}

//-----------------------------------------------------------------------------------------

// Draw all icons in the toolbar
void Toolsbar::drawIcon(sf::RenderWindow& window)
{
    for (int i = 0; i < iconSize; i++)
        window.draw(m_pictures[i]); // Draw each icon sprite on the window
}

//-----------------------------------------------------------------------------------------

// Find the character (icon) at a given location in the toolbar
int Toolsbar::findCharacter(sf::Vector2f location) const
{
    // Iterate through each icon to check if its position matches the given location
    for (int i = 0; i < iconSize; i++) {
        if ((m_pictures[i].getPosition().x == location.x)
            && (m_pictures[i].getPosition().y == location.y)) {
            return i; // Return the index of the icon if its position matches the given location
        }
    }

    return iconSize; // Return iconSize if no icon is found at the given location
}

//-----------------------------------------------------------------------------------------

// Get the sprite of an icon at a given index
sf::Sprite Toolsbar::getspirt(int i)
{
    return m_pictures[i]; // Return the sprite of the icon at the given index
}
