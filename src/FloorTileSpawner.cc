export module floortilespawner;

import spatial;
import worldelement;
import worldelementspawner;

export class FloorTileSpawner: public WorldElementSpawner {
    virtual WorldElement *doSpawn(const Location &loc) const override;
};
