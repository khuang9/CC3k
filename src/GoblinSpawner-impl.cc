module goblinspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import dodge;
import lootextra;
import statsmanager;
import statmodifier;
import player;

std::unique_ptr<WorldElement> GoblinSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 110;
    constexpr int ATK = 15;
    constexpr int DEF = 20;

    constexpr int LOOT = 5;
    constexpr double DODGE = 0.5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<Dodge>(std::move(mods), DODGE);

    std::vector<std::unique_ptr<StatsManager>> stman;
    stman.emplace_back(std::make_unique<LootExtra>(
        LOOT
    ));

    auto e = std::make_unique<Player>(cell, MAX_HP, MAX_HP, ATK, DEF, Race::Goblin, std::move(mods), std::move(stman));
    return e;
}
