export module smallgoldspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class SmallGoldSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
