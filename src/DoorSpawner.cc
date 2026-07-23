export module doorspawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class DoorSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
