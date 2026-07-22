module floor;

import spatial;
import <sstream>;

Floor::Floor(std::string file) {
    std::ifstream in{file};

    std::string line;
    size_t maxLineLength = 0;

    while (std::getline(in, line)) {
        grid.emplace_back(line.begin(), line.end());
        maxLineLength = std::max(maxLineLength, line.size());
    }

    if (grid.empty()) return;

    for (auto &row : grid) {
        while (row.size() < maxLineLength) row.emplace_back(' ');
    }

    int numRows = grid.size();
    int numCols = maxLineLength;

    std::vector<std::vector<bool>> visited(
        numRows,
        std::vector<bool>(numCols, false)
    );

    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            if (visited[r][c] || NON_CHAMBER_CELLS.contains(grid[r][c])) continue;
            // chambers.emplace_back(r, c, grid, visited, NON_CHAMBER_CELLS, td);
            chambers.emplace_back(r, c, grid, visited, NON_CHAMBER_CELLS, this);
        }
    }

    // td->setDisplay(grid);
}

void Floor::updateGrid(const Chamber &c) {
    // int x = 0;
    // const auto &cells = c.getCells();
    // for (const auto &[i, row] : cells) {
    //     for (const auto &[j, v] : row) {
    //         if (v.size() > 1) x += 1;
    //         grid[i][j] = (v.empty() || !v.back()) ? ' ' : v.back()->getChar();
    //     }
    // }
    // std::cout << x << std::endl;
}

void Floor::doNotify(Subject &whoFrom) {
    Location fromLoc = whoFrom.getState().loc;
    grid[fromLoc.row][fromLoc.col] = whoFrom.getInfo().occupantChar;
}

// void Floor::print() const {
//     for (const auto &row : grid) {
//         for (auto c : row) {
//             std::cout << c;
//         }
//         std::cout << std::endl;
//     }
// }

std::ostream &operator<<(std::ostream &out, const Floor &f) {
    for (const auto &row : f.grid) {
        for (auto c : row) {
            out << c;
        }
        out << std::endl;
    }

    out << "Chambers:" << std::endl;
    for (const auto &ch : f.chambers) {
        out << ch << std::endl;
    }

    return out;
}
