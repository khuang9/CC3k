module elfspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import drop;
import enemy;
import multiattack;
import normalgoldspawner;
import smallgoldspawner;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> ElfSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 140;
    constexpr int ATK = 30;
    constexpr int DEF = 10;
    constexpr int NUM_ATTACKS = 2;
    const Race EXCEPTION = Race::Drow;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<MultiAttack>(std::move(mods), NUM_ATTACKS, EXCEPTION);

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(1, std::make_unique<SmallGoldSpawner>());
    drops.emplace_back(1, std::make_unique<NormalGoldSpawner>());

    auto e = std::make_unique<Enemy>('E', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Elf, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
