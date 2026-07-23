module doorspawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> DoorSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('+', Colour::None, WorldElementType::Door, cell);
}
