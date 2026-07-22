module floortilespawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *FloorTileSpawner::doSpawn(const Location &loc) const {
    return new EnvironmentTile('.', Colour::None, WorldElementType::Floor, loc);
}
