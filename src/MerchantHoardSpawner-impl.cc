module merchanthoardspawner;

import treasure;

std::unique_ptr<WorldElement> MerchantHoardSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = 4;

    auto e = std::make_unique<Treasure>(cell, VALUE);
    return e;
}
