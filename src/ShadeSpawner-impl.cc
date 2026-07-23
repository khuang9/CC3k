module shadespawner;

import player;

std::unique_ptr<WorldElement> ShadeSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 125;
    constexpr int ATK = 25;
    constexpr int DEF = 25;

    auto e = std::make_unique<Player>(cell, MAX_HP, MAX_HP, ATK, DEF, Race::Shade);
    return e;
}
