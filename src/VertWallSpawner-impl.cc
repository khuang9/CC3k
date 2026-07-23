module vertwallspawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> VertWallSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('|', Colour::None, WorldElementType::VertWall, cell);
}
