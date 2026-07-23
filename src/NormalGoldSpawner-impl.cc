module normalgoldspawner;

import treasure;

std::unique_ptr<WorldElement> NormalGoldSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = 2;

    auto e = std::make_unique<Treasure>(cell, VALUE);
    return e;
}
