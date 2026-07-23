module floortilespawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> FloorTileSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('.', Colour::None, WorldElementType::FloorTile, cell);
}
