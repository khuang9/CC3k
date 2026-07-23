export module passagespawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class PassageSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
