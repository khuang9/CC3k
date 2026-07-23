export module chamber;

import <functional>;
import <iostream>;
import <memory>;
import <queue>;
import <unordered_map>;
import <unordered_set>;
import <vector>;
// import subjectobserver;
import worldelement_and_cell;
import worldelementspawner;
import spatial;
import environmenttile;
import subjectobserver;
import stairsspawner;

export class Chamber {
  public:
    using CellMap = std::unordered_map<int, std::unordered_map<int, Cell*>>;
    using SpawnerFactory = std::function<std::unique_ptr<WorldElementSpawner>()>;
    // const CellMap &getCells() const;
    Chamber(
        int startRow,
        int startCol,
        const std::vector<std::vector<char>> &grid,
        const std::vector<std::vector<std::unique_ptr<Cell>>> &allCells,
        std::vector<std::vector<bool>> &visited,
        const std::unordered_set<char> &boundaryChars,
        Observer *displayer);
    bool contains(int row, int col) const;
    friend std::ostream &operator<<(std::ostream &out, const Chamber &c);

  public:
    CellMap cells;
    int numCells;
    std::vector<std::unique_ptr<WorldElement>> elements;
    std::unique_ptr<WorldElement> spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c);

    static inline const std::unordered_map<char, SpawnerFactory> SPAWNER_MAP = {
        {'/', [] { return std::make_unique<StairsSpawner>(); }},
    };
};

export std::ostream &operator<<(std::ostream &out, const Chamber &c);
