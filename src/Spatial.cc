export module spatial;

export struct Direction {
    int dRow;
    int dCol;
};

export struct Location {
    int row;
    int col;

    bool inNeighbourhood(const Location &other) const;
    bool operator==(const Location &other) const;
    bool operator!=(const Location &other) const;
    Direction operator-(const Location &other) const;
    Location operator+(const Direction &other) const;
};