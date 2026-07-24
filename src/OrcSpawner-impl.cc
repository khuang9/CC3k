module orcspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import drop;
import enemy;
import magnifyattack;
import normalgoldspawner;
import smallgoldspawner;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> OrcSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 140;
    constexpr int ATK = 30;
    constexpr int DEF = 10;
    constexpr double BUFF = 1.5;
    const Race VICTIM = Race::Goblin;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<MagnifyAttack>(std::move(mods), BUFF, VICTIM);

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(1, std::make_unique<SmallGoldSpawner>());
    drops.emplace_back(1, std::make_unique<NormalGoldSpawner>());

    auto e = std::make_unique<Enemy>('O', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Orc, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
