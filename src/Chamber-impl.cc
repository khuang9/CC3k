module chamber;

import <utility>;
import colour;
import floortilespawner;
import worldelementtype;

Chamber::Chamber(
    int startRow,
    int startCol,
    const std::vector<std::vector<char>> &grid,
    const std::vector<std::vector<std::unique_ptr<Cell>>> &allCells,
    std::vector<std::vector<bool>> &visited,
    const std::unordered_set<char> &boundaryChars,
    Observer *displayer): numCells{0} {

    std::queue<std::pair<int, int>> toCheck;
    toCheck.push({startRow, startCol});
    // for (const auto &row : grid) {
    //     for (auto c : row) std::cout << c;
    //     std::cout << std::endl;
    // }
    while (!toCheck.empty()) {
        auto [r, c] = toCheck.front();
        toCheck.pop();

        if (visited[r][c]) continue;
        
        visited[r][c] = true;
        if (boundaryChars.contains(grid[r][c])) continue;

        cells[r][c] = allCells[r][c].get();
        
        // if (cells[r][c].size() == 1) ++numCells;

        toCheck.push({r - 1, c});
        toCheck.push({r, c + 1});
        toCheck.push({r + 1, c});
        toCheck.push({r, c - 1});
    }

    for (const auto &[r, row] : cells) {
        for (const auto &[c, cell] : row) {
            elements.emplace_back(spawnElement(std::make_unique<FloorTileSpawner>(), r, c));
            if (SPAWNER_MAP.contains(grid[r][c])) {
                elements.emplace_back(spawnElement(SPAWNER_MAP.at(grid[r][c])(), r, c));
            }
        }
    }
}

bool Chamber::contains(int row, int col) const {
    return (cells.contains(row) && cells.at(row).contains(col));
}

// const Chamber::CellMap &Chamber::getCells() const {
//     return cells;
// }

std::unique_ptr<WorldElement> Chamber::spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c) {
    if (!cells.contains(r) || !cells.at(r).contains(c)) return nullptr;
    auto el = s->spawn(cells.at(r).at(c));
    return el;
}

std::ostream &operator<<(std::ostream &out, const Chamber &c) {
    out << "Num cells: " << c.numCells;
    return out;
}