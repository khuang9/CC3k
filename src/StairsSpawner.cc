export module stairsspawner;

import <memory>;
import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class StairsSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
