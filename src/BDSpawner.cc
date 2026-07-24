export module bdspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class BDSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
