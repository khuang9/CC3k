module horizwallspawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *HorizWallSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('-', Colour::None, WorldElementType::HorizWall, cell);
}
