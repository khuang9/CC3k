export module waspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class WASpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
