
class Tile {
public:
    Tile(); 
    Tile(const Tile& other); 
    Tile& operator=(const Tile& other); 
    ~Tile(); 
    char getSymbol() const;
    void setSymbol(char newSymbol);

private:
    char symbol;
};
