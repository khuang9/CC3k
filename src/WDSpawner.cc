export module wdspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class WDSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
