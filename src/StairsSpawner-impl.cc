module stairsspawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> StairsSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('/', Colour::Blue, WorldElementType::Stairs, cell);
}
