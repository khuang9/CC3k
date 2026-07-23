export module trollspawner;

import <memory>;
import race;
import worldelement_and_cell;
import worldelementspawner;

export class TrollSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
