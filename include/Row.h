#include <stdexcept>

#include "Tile.h" 

class Row {
public:
    explicit Row(int size = 0, const Tile& value = Tile());
    Row(const Row& other);
    Row& operator=(const Row& other);
    ~Row();
    const Tile& at(int index) const;
    Tile& at(int index);
    void push_back(const Tile& value);
    int size() const;
    bool empty() const;

private:
    Tile* m_tiles;
    size_t m_size;

    void copyData(const Row& other);
    void freeMemory();
};

