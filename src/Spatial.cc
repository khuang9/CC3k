export module spatial;

import <iostream>;

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

export std::ostream &operator<<(std::ostream &out, const Location &loc);
export std::ostream &operator<<(std::ostream &out, const Direction &dir);
