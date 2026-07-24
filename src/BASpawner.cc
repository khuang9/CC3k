export module baspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class BASpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
