module dwarfspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import enemy;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> DwarfSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 100;
    constexpr int ATK = 20;
    constexpr int DEF = 30;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();

    std::vector<std::unique_ptr<StatsManager>> stman{};

    auto e = std::make_unique<Enemy>('W', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Dwarf, std::move(mods), std::move(stman));
    return e;
}
