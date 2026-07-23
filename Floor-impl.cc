module floor;

import spatial;
import <sstream>;

Floor::Floor(std::string file) {
    std::ifstream in{file};

    std::string line;
    size_t maxLineLength = 0;

    int r = 0;
    while (std::getline(in, line)) {
        grid.emplace_back(line.begin(), line.end());
        maxLineLength = std::max(maxLineLength, line.size());
        cells.emplace_back();
        for (size_t c = 0; c < line.size(); ++c) {
            cells.back().emplace_back(std::make_unique<Cell>(r, c));
        }
        ++r;
    }

    if (grid.empty()) return;

    for (auto &row : grid) {
        while (row.size() < maxLineLength) row.emplace_back(' ');
    }

    for (auto &row : cells) {
        while (row.size() < maxLineLength) row.emplace_back(nullptr);
    }

    int numRows = grid.size();
    int numCols = maxLineLength;
    
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            std::vector<std::vector<Cell*>> neighbours;
            for (int i = r - 1; i <= r + 1; ++i) {
                neighbours.emplace_back();
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (0 <= i && i < numRows &&
                        0 <= j && j < numCols &&
                        !(i == r && j == c)) {
                        cells[r][c]->attach(cells[i][j].get());
                        neighbours.back().emplace_back(cells[i][j].get());
                    } else {
                        neighbours.back().emplace_back(nullptr);
                    }
                }
            }
            cells[r][c]->setNeighbours(neighbours);
        }
    }

    std::vector<std::vector<bool>> visited(
        numRows,
        std::vector<bool>(numCols, false)
    );

    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            if (NON_CHAMBER_CELLS.contains(grid[r][c])) {
                if (NON_CHAMBER_SPAWNER_MAP.contains(grid[r][c])) {
                    auto el = NON_CHAMBER_SPAWNER_MAP.at(grid[r][c])()->spawn(cells[r][c].get());
                    cells[r][c]->attachElement(el);
                }
                continue;
            }
            if (visited[r][c]) continue;
            // chambers.emplace_back(r, c, grid, visited, NON_CHAMBER_CELLS, td);
            chambers.emplace_back(r, c, grid, cells, visited, NON_CHAMBER_CELLS, this);
        }
    }

    // td->setDisplay(grid);
}

void Floor::doNotify(Subject &whoFrom) {
    // Location fromLoc = whoFrom.getInfo().loc;
    // // std::cout << "Notified of change in " << fromLoc << " with " << whoFrom.getInfo().occupantChar << std::endl;
    // grid[fromLoc.row][fromLoc.col] = whoFrom.getInfo().occupantChar;
}

WorldElement *Floor::spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c) {
    for (auto &ch : chambers) {
        if (ch.contains(r, c)) {
            return ch.spawnElement(s, r, c);
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &out, const Floor &f) {
    for (const auto &row : f.cells) {
        for (const auto &cell : row) {
            out << cell->getInfo().occupantChar;
        }
        out << std::endl;
    }

    out << "Chambers:" << std::endl;
    for (const auto &ch : f.chambers) {
        out << ch << std::endl;
    }

    return out;
}
