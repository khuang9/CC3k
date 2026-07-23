module floortilespawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *FloorTileSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('.', Colour::None, WorldElementType::FloorTile, cell);
}
