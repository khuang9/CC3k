module passagespawner;

import colour;
import environmenttile;
import worldelementtype;

WorldElement *PassageSpawner::doSpawn(Cell *cell) const {
    return new EnvironmentTile('#', Colour::None, WorldElementType::Passage, cell);
}
