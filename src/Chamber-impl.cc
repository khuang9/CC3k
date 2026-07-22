module chamber;

import <utility>;
import colour;
import floortilespawner;
import worldelementtype;

Chamber::Chamber(
    int startRow,
    int startCol,
    const std::vector<std::vector<char>> &grid,
    std::vector<std::vector<bool>> &visited,
    const std::unordered_set<char> &boundaryChars,
    Observer *displayer) {

    std::queue<std::pair<int, int>> toCheck;
    toCheck.push({startRow, startCol});

    while (!toCheck.empty()) {
        auto [r, c] = toCheck.front();
        toCheck.pop();

        if (visited[r][c]) continue;
        
        visited[r][c] = true;
        if (boundaryChars.contains(grid[r][c])) continue;

        cells[r][c] = new Cell(r, c);
        
        // if (cells[r][c].size() == 1) ++numCells;

        toCheck.push({r - 1, c});
        toCheck.push({r, c + 1});
        toCheck.push({r + 1, c});
        toCheck.push({r, c - 1});
    }

    for (const auto &[r, row] : cells) {
        for (const auto &[c, cell] : row) {
            cell->attach(displayer);
            std::vector<std::vector<Cell*>> neighbours;
            for (int i = r - 1; i <= r + 1; ++i) {
                neighbours.emplace_back();
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (cells.contains(i) && cells[i].contains(j) && !(i == r && j == c)) {
                        cell->attach(cells[i][j]);
                        neighbours.back().emplace_back(cells[i][j]);
                    } else {
                        neighbours.back().emplace_back(nullptr);
                    }
                }
            }
            cell->setNeighbours(neighbours);
            spawnElement(std::make_unique<FloorTileSpawner>(), r, c);
            if (SPAWNER_MAP.contains(grid[r][c])) {
                spawnElement(SPAWNER_MAP.at(grid[r][c]), r, c);
            }
        }
    }
}

const Chamber::CellMap &Chamber::getCells() const {
    return cells;
}

void Chamber::spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c) {
    if (!cells.contains(r) || !cells.at(r).contains(c)) return;
    auto el = s->spawn({r, c});
    cells.at(r).at(c)->attachElement(el);
}

std::ostream &operator<<(std::ostream &out, const Chamber &c) {
    out << "Num cells: " << c.numCells;
    return out;
}