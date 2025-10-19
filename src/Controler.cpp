#include "Controler.h"

Controller::Controller()
{
}

//-----------------------------------------------------------------------------------------
void Controller::run()
{
    // Main loop to run the program until user exits
    do {
        // Reset delete mode and read data for the board
        m_board.setDeletedMode();
        m_board.readData();

        // Create the main window for the game
        sf::RenderWindow window(sf::VideoMode(1300, 800), "Tom&Jerry", sf::Style::Close | sf::Style::Titlebar);
        sf::Texture Background;

        // Load and set background image
        Background.loadFromFile("background.png");
        m_background.setTexture(Background);

        // Scale background to fit window size
        m_background.setScale(sf::Vector2f((1300 / m_background.getGlobalBounds().width), (800 / m_background.getGlobalBounds().height)));

        // Event loop to handle user input and update display
        while (window.isOpen())
        {
            window.clear();
            window.draw(m_background); // Draw background
            m_board.draw(window); // Draw board

            // Wait for events and respond accordingly
            if (auto event = sf::Event{}; window.waitEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close(); // Close window if close button is clicked
                    break;

                case sf::Event::MouseButtonReleased:
                    m_board.ClickMouse(event, window); // Process mouse click
                    break;
                }

                window.display(); // Update window display
            }
        }
    } while (m_board.getDeleteMode()); // Repeat loop if delete mode is enabled
}
