export module chamber;

import <iostream>;
import <memory>;
import <queue>;
import <unordered_map>;
import <unordered_set>;
import <vector>;
// import subjectobserver;
import cell;
import worldelement;
import worldelementspawner;
import spatial;
import environmenttile;
import subjectobserver;

export class Chamber {
  public:
    using CellMap = std::unordered_map<int, std::unordered_map<int, Cell*>>;
    const CellMap &getCells() const;
    Chamber(
        int startRow,
        int startCol,
        const std::vector<std::vector<char>> &grid,
        std::vector<std::vector<bool>> &visited,
        const std::unordered_set<char> &boundaryChars,
        Observer *displayer);
    
    friend std::ostream &operator<<(std::ostream &out, const Chamber &c);

  private:
    CellMap cells;
    int numCells;
    void spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c);

    static inline const std::unordered_map<char, std::unique_ptr<WorldElementSpawner>> SPAWNER_MAP{
        // {'+', std::make_unique<FloorTileSpawner>()},
    };
};

export std::ostream &operator<<(std::ostream &out, const Chamber &c);
