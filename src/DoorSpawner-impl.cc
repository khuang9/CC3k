module doorspawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *DoorSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('+', Colour::None, WorldElementType::Door, cell);
}
