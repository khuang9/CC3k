export module worldelementspawner;

import <memory>;
import spatial;
import worldelement_and_cell;

export class WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const = 0;
  public:
    std::unique_ptr<WorldElement> spawn(Cell *cell) const;
};
