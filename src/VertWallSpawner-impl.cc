module vertwallspawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *VertWallSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('|', Colour::None, WorldElementType::VertWall, cell);
}
