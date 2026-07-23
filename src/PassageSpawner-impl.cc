module passagespawner;

import colour;
import environmenttile;
import worldelementtype;

std::unique_ptr<WorldElement> PassageSpawner::doSpawn(Cell *cell) const {
    return std::make_unique<EnvironmentTile>('#', Colour::None, WorldElementType::Passage, cell);
}
