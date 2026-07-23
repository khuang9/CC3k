module stairsspawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *StairsSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('/', Colour::Blue, WorldElementType::Stairs, cell);
}
