module humanspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import drop;
import dropsitems;
import enemy;
import normalgoldspawner;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> HumanSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 140;
    constexpr int ATK = 20;
    constexpr int DEF = 20;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<DropsItems>(std::move(mods));

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(2, std::make_unique<NormalGoldSpawner>());

    auto e = std::make_unique<Enemy>('H', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Human, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
