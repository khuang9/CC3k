export module halflingspawner;

import <memory>;
import race;
import worldelement_and_cell;
import worldelementspawner;

export class HalflingSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
