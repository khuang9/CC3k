module dwarfspawner;

import enemy;

std::unique_ptr<WorldElement> DwarfSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 100;
    constexpr int ATK = 20;
    constexpr int DEF = 30;

    auto e = std::make_unique<Enemy>('W', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Dwarf);
    return e;
}
