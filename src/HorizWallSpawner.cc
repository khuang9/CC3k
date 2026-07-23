export module horizwallspawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class HorizWallSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
