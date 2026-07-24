module dwarfspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import drop;
import enemy;
import normalgoldspawner;
import smallgoldspawner;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> DwarfSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 100;
    constexpr int ATK = 20;
    constexpr int DEF = 30;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(1, std::make_unique<SmallGoldSpawner>());
    drops.emplace_back(1, std::make_unique<NormalGoldSpawner>());

    auto e = std::make_unique<Enemy>('W', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Dwarf, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
