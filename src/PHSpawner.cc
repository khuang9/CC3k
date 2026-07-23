export module phspawner;

import <memory>;
import worldelement_and_cell;
import worldelementspawner;

export class PHSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
