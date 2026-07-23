module smallgoldspawner;

import treasure;

std::unique_ptr<WorldElement> SmallGoldSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = 1;

    auto e = std::make_unique<Treasure>(cell, VALUE);
    return e;
}
