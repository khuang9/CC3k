module spatial;

bool Location::inNeighbourhood(const Location &other) const {
    return (
        -1 <= row - other.row && row - other.row <= 1 &&
        -1 <= col - other.col && col - other.col <= 1
    );
}

bool Location::operator==(const Location &other) const {
    return (row == other.row && col == other.col);
}

bool Location::operator!=(const Location &other) const {
    return !(operator==(other));
}

Direction Location::operator-(const Location &other) const {
    return {row - other.row, col - other.col};
}

Location Location::operator+(const Direction &other) const {
    return {row + other.dRow, col + other.dCol};
}

std::ostream &operator<<(std::ostream &out, const Location &loc) {
    out << "(" << loc.row << ", " << loc.col << ")";
    return out;
}

std::ostream &operator<<(std::ostream &out, const Direction &dir) {
    out << "(" << dir.dRow << ", " << dir.dCol << ")";
    return out;
}
