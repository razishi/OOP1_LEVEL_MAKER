#include "Board.h"

// Constructor for the Board class
Board::Board()
{
    // Initialize the board and other member variables
    setBoard();
    m_deleteMode = false;
    m_MouseInMap = false;
    m_selectedIcon = iconSize;
    m_RectMouseMove.setSize(sf::Vector2f(50, 50)); // Assuming m_RectMouseMove is a member variable
}

//-----------------------------------------------------------------------------------------
void Board::readData()
{
    std::fstream input;
    input.open("Board.txt");

    if (!input.is_open()) {
        // If file doesn't exist, prompt user for row and column inputs
        std::cout << "enter the num of rows (between 1 - 16): ";
        std::cin >> m_row;
        // Input validation for row
        if (m_row > 16)
        {
            while (1)
            {
                std::cout << "please enter valid number of rows (between 1 - 16): ";
                std::cin >> m_row;
                if (m_row <= 16)
                {
                    break;
                }
            }
        }
        // Similar input validation for column
        std::cout << "enter the num of cols (between 1 - 21): ";
        std::cin >> m_col;
        if (m_col > 21)
        {
            while (1)
            {
                std::cout << "please enter valid number of cols (between 1 - 21): ";
                std::cin >> m_col;
                if (m_col <= 21)
                {
                    break;
                }
            }
        }

        setBoard(); // Initialize the board with user-defined dimensions
    }
    else
    {
        // If file exists, read row and column from the file
        char c;
        input >> m_row >> m_col;
        input.get();
        setBoard(); // Initialize the board with file-defined dimensions
        // Read characters for each cell of the board from the file
        for (int i = 0; i < m_row; i++)
        {
            for (int j = 0; j < m_col; j++)
            {
                c = input.get();
                if (c != '\n' && c != EOF) // Check for end of line and file
                {
                    m_board.at(i).at(j).setSymbol(c); // Set the symbol for each cell
                }
            }
            input.get(); // To consume the newline character at the end of each row
        }
    }
    resetBackground(); // Reset the background of the board
}
//-----------------------------------------------------------------------------------------

// Reset the background size and position based on the dimensions of the board
void Board::resetBackground()
{
    m_xstart = ((1300 - (50 * m_col)) / 2) - 50;
    m_ystart = ((800 - (50 * m_row)) / 2);

    if (m_col % 2 != 0)
        m_xstart += (50 / 2);

    if (m_row % 2 != 0)
        m_ystart += (50 / 2);

    m_background.setSize(sf::Vector2f(m_col * 50, m_row * 50)); // Set background size
    m_background.setFillColor(sf::Color(128,128,128)); // Set background color
    m_background.setPosition(sf::Vector2f(m_xstart, m_ystart)); // Set background position
}

//-----------------------------------------------------------------------------------------
// Draw grid lines for rows and columns of the board
void Board::drawRowCols(sf::RenderWindow& window)
{
    sf::RectangleShape col(sf::Vector2f(1, m_row * 50)); // Vertical line shape for columns
    sf::RectangleShape row(sf::Vector2f(m_col * 50, 1)); // Horizontal line shape for rows

    // Draw vertical lines for columns
    for (int i = 0; i <= m_col; i++) {
        col.setFillColor(sf::Color::Black);
        col.setPosition(sf::Vector2f(m_xstart + (i * 50), m_ystart));
        window.draw(col);
    }

    // Draw horizontal lines for rows
    for (int i = 0; i <= m_row; i++) {
        row.setFillColor(sf::Color::Black);
        row.setPosition(sf::Vector2f(m_xstart, m_ystart + (i * 50)));
        window.draw(row);
    }
}
//-----------------------------------------------------------------------------------------
// Find the index of a character in the character array
int Board::findeindexVector(char c)const
{
    for (int i = 0; i < iconSize; i++)
        if (m_charactersArray[i] == c)
            return i;

    return c;
}
//-----------------------------------------------------------------------------------------
// Reset the delete mode flag
void Board::setDeletedMode()
{
    m_deleteMode = false;
}

//-----------------------------------------------------------------------------------------
// Save the current state of the board to a file
void Board::saveMap()
{
    std::ofstream output("Board.txt"); // Open file for writing
    if (!output.is_open())
    {
        std::cerr << "Failed to open Board.txt for writing." << std::endl; // Print error message if file cannot be opened
        return; // Exit if file cannot be opened
    }

    // Write the dimensions of the board to the file
    output << m_row << " " << m_col << "\n";

    // Iterate over the board and write each symbol to the file
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++)
            output << m_board.at(i).at(j).getSymbol();
        output << "\n"; // End each row with a new line
    }

    output.close(); // Close the file
}
//-----------------------------------------------------------------------------------------
// Get the delete mode flag
bool Board::getDeleteMode()
{
    return m_deleteMode;
}

//-----------------------------------------------------------------------------------------

// Draw an image corresponding to a character on the board
void Board::drawPic(sf::RenderWindow& window, char character, sf::Vector2f position) {
    int iconIndex = findeindexVector(character); // Find index of character in character array
    if (iconIndex >= 0) {
        sf::Sprite pictureicon = m_Toolsbar.getspirt(iconIndex); // Get sprite corresponding to character
        pictureicon.setScale(1, 1); // Set scale of sprite
        pictureicon.setPosition(m_xstart + (position.y * 50), m_ystart + (position.x * 50)); // Set position of sprite
        window.draw(pictureicon); // Draw sprite on window
    }
}

//-----------------------------------------------------------------------------------------

// Draw the entire board including background, grid lines, and icons
void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_background); // Draw background
    m_Toolsbar.drawIcon(window); // Draw toolbar icons
    drawRowCols(window); // Draw grid lines

    // Draw icons for each cell in the board
    for (int i = 0; i < m_board.size(); i++) {
        for (int y = 0; y < m_board.at(i).size(); y++) {
            sf::Vector2f position(i, y);
            if (m_board.at(i).at(y).getSymbol() != ' ')
            {
                drawPic(window, m_board.at(i).at(y).getSymbol(), position); // Draw icon at position
            }
        }
    }

}

//-----------------------------------------------------------------------------------------

// Process mouse click events on the board
void Board::ClickMouse(sf::Event evnt, sf::RenderWindow& window)
{
    // Calculate position of mouse click
    sf::Vector2i positionMap((evnt.mouseButton.x / 50) * 50, (evnt.mouseButton.y / 50) * 50);
    sf::Vector2i positionToolbar((evnt.mouseButton.x / (50 * 2)) * 50 * 2, (evnt.mouseButton.y / SIZEOFIMGS) * SIZEOFIMGS);

    // Check if click occurred on toolbar or board
    if (positionToolbar.x == 0)
    {
        ClickToolbar(sf::Vector2f(positionToolbar), evnt, window); // Process toolbar click
    }
    else {
        // Process click on the board
        size_t indexX = (positionMap.x - m_xstart) / 50;
        size_t indexY = (positionMap.y - m_ystart) / 50;

        // Check if selected icon is valid and position is within board bounds
        if (m_selectedIcon != NONE && indexY < m_board.size() && indexX < m_board[indexY].size()) {
            if (m_board.at(indexY).at(indexX).getSymbol() == ' ') {
                // Place icon on empty cell
                if (m_selectedIcon != DELETE && m_selectedIcon != SAVE && m_selectedIcon != DELETEALL) {
                    if (m_selectedIcon == Mouse && !m_MouseInMap) {
                        m_board.at(indexY).at(indexX).setSymbol(m_charactersArray[m_selectedIcon]);
                        m_MouseInMap = true;
                    }
                    else {
                        if (m_selectedIcon != Mouse) {
                            m_board.at(indexY).at(indexX).setSymbol(m_charactersArray[m_selectedIcon]);
                        }
                    }
                }
            }
            else {
                // Delete icon from cell if in delete mode
                if (m_selectedIcon == DELETE) {
                    if (m_board.at(indexY).at(indexX).getSymbol() == '%')
                        m_MouseInMap = false;
                    m_board.at(indexY).at(indexX).setSymbol(' ');
                }
            }
            draw(window); // Redraw the board
        }
    }
}

//-----------------------------------------------------------------------------------------

// Clear the entire board by setting all symbols to empty
void Board::clearBoard() {
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            m_board.at(i).~Row(); // Free Memory 
        }
    }
}

//-----------------------------------------------------------------------------------------

// Initialize the board with empty symbols based on row and column dimensions
void Board::setBoard() {
    m_board.clear(); // Clear existing rows to start fresh
    for (int i = 0; i < m_row; i++) {
        Row newRow(m_col); // Create a new Row with the correct number of columns (tiles)
        m_board.push_back(newRow); // Add the new Row to the board
    }
}

//-----------------------------------------------------------------------------------------

// Process toolbar click events
void Board::ClickToolbar(sf::Vector2f positon, sf::Event event, sf::RenderWindow& window)
{
    m_selectedIcon = m_Toolsbar.findCharacter(positon); // Find selected icon from toolbar

    // Handle actions based on selected icon
    if (m_selectedIcon == DELETEALL) {
        setBoard(); // Clear the board
        remove("board.txt"); // Remove the board file
        window.close(); // Close the window
        m_selectedIcon = iconSize; // Reset selected icon
        m_deleteMode = true; // Set delete mode
        m_MouseInMap = false; // Reset mouse in map flag
    }

    if (m_selectedIcon == SAVE)
        saveMap(); // Save the current board state to a file
}
