module halflingspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import dodge;
import drop;
import enemy;
import normalgoldspawner;
import smallgoldspawner;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> HalflingSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 100;
    constexpr int ATK = 15;
    constexpr int DEF = 20;

    constexpr double DODGE = 0.5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<Dodge>(std::move(mods), DODGE);

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(1, std::make_unique<SmallGoldSpawner>());
    drops.emplace_back(1, std::make_unique<NormalGoldSpawner>());

    auto e = std::make_unique<Enemy>('L', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Halfling, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
