#include "Tile.h"

// Constructor with default parameters
Tile::Tile()
{
    symbol = ' ';
}
//-----------------------------------------------------------------------------------------
// Copy constructor
Tile::Tile(const Tile& other) : symbol(other.symbol) {}
//-----------------------------------------------------------------------------------------
// Copy assignment operator
Tile& Tile::operator=(const Tile& other) {
    if (this != &other) {

        symbol = other.symbol;
    }
    return *this;
}
//-----------------------------------------------------------------------------------------
// Destructor
Tile::~Tile() {}

//-----------------------------------------------------------------------------------------
// Getter for the symbol
char Tile::getSymbol() const {
    return symbol;
}

//-----------------------------------------------------------------------------------------
// Setter for the symbol
void Tile::setSymbol(char newSymbol) {
    symbol = newSymbol;

}