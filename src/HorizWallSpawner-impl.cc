module horizwallspawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> HorizWallSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('-', Colour::None, WorldElementType::HorizWall, cell);
}
