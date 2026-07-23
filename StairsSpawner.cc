export module stairsspawner;

import spatial;
import worldelement_and_cell;
import worldelementspawner;

export class StairsSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const override;
};
