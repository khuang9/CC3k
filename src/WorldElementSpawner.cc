export module worldelementspawner;

import spatial;
import worldelement_and_cell;

export class WorldElementSpawner {
    virtual WorldElement *doSpawn(Cell *cell) const = 0;
  public:
    WorldElement *spawn(Cell *cell) const;
};
