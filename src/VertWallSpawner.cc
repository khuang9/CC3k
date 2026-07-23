export module vertwallspawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class VertWallSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
