export module floortilespawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class FloorTileSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
