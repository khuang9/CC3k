export module passagespawner;

import <memory>;
import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class PassageSpawner: public WorldElementSpawner {
    virtual std::unique_ptr<WorldElement> doSpawn(Cell *cell) const override;
};
