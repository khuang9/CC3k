export module worldelementspawner;

import spatial;
import worldelement;

export class WorldElementSpawner {
    virtual WorldElement *doSpawn(const Location &loc) const = 0;
  public:
    WorldElement *spawn(const Location &loc) const;
};
