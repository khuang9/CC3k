export module shadespawner;

import <memory>;
import race;
import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class ShadeSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
