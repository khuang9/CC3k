module rhspawner;

import healthpotion;

std::unique_ptr<WorldElement> RHSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = 10;

    auto e = std::make_unique<HealthPotion>(cell, VALUE);
    return e;
}
