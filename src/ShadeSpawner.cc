export module shadespawner;

import race;
import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class ShadeSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
