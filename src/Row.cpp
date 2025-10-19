#include "Row.h"

// Constructor: Initializes Row with a specified size and default Tile value
Row::Row(int size, const Tile& value) : m_size(size), m_tiles(new Tile[size]) {
    // Initialize each element of the Row with the specified value
    for (int i = 0; i < size; ++i) {
        m_tiles[i] = value;
    }
}

//-----------------------------------------------------------------------------------------

// Copy constructor: Copies data from another Row object
Row::Row(const Row& other) : m_tiles(nullptr), m_size(0) {
    copyData(other); // Call helper function to copy data
}

//-----------------------------------------------------------------------------------------

// Assignment operator: Assigns data from another Row object
Row& Row::operator=(const Row& other) {
    if (this != &other) {
        freeMemory(); // Free existing memory
        copyData(other); // Copy data from other Row
    }
    return *this;
}

//-----------------------------------------------------------------------------------------

// Destructor: Frees memory used by the Row
Row::~Row() {
    freeMemory(); // Call helper function to free memory
}

//-----------------------------------------------------------------------------------------

// Accessor function to get the Tile at a specified index (const version)
const Tile& Row::at(int index) const {
    // Check if index is within bounds
    if (index >= 0 && index < m_size) {
        return m_tiles[index]; // Return the Tile at the specified index
    }
    else {
        throw std::out_of_range("Index out of range"); // Throw an exception if index is out of range
    }
}

//-----------------------------------------------------------------------------------------

// Accessor function to get the Tile at a specified index (non-const version)
Tile& Row::at(int index) {
    // Check if index is within bounds
    if (index >= 0 && index < m_size) {
        return m_tiles[index]; // Return the Tile at the specified index
    }
    else {
        throw std::out_of_range("Index out of range"); // Throw an exception if index is out of range
    }
}

//-----------------------------------------------------------------------------------------

// Adds a new Tile to the end of the Row
void Row::push_back(const Tile& value) {
    // Create a new array with increased size
    Tile* newTiles = new Tile[m_size + 1];
    // Copy existing elements to the new array
    for (int i = 0; i < m_size; ++i) {
        newTiles[i] = m_tiles[i];
    }
    // Add the new Tile to the end of the new array
    newTiles[m_size] = value;
    // Increase the size of the Row
    ++m_size;
    // Free memory used by the old array
    delete[] m_tiles;
    // Update m_tiles to point to the new array
    m_tiles = newTiles;
}

//-----------------------------------------------------------------------------------------

// Returns the size of the Row
int Row::size() const {
    return m_size; // Return the size member variable
}

//-----------------------------------------------------------------------------------------

// Checks if the Row is empty
bool Row::empty() const {
    return m_size == 0; // Return true if size is 0, indicating the Row is empty
}

//-----------------------------------------------------------------------------------------

// Helper function to copy data from another Row object
void Row::copyData(const Row& other) {
    m_size = other.m_size; // Copy the size
    m_tiles = new Tile[m_size]; // Allocate memory for the new array
    // Copy each element from the other Row to the new array
    for (int i = 0; i < m_size; ++i) {
        m_tiles[i] = other.m_tiles[i];
    }
}

//-----------------------------------------------------------------------------------------

// Helper function to free memory used by the Row
void Row::freeMemory() {
    delete[] m_tiles; // Delete the dynamically allocated array
    m_tiles = nullptr; // Set m_tiles to nullptr to avoid dangling pointer
    m_size = 0; // Reset the size to 0
}
