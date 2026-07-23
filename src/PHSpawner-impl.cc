module phspawner;

import healthpotion;

std::unique_ptr<WorldElement> PHSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = -10;

    auto e = std::make_unique<HealthPotion>(cell, VALUE);
    return e;
}
