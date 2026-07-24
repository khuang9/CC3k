module vampirespawner;

import <limits>;
import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import dodge;
import healonhit;
import statsmanager;
import statmodifier;
import player;

std::unique_ptr<WorldElement> VampireSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = std::numeric_limits<int>::max();
    constexpr int HP = 50;
    constexpr int ATK = 25;
    constexpr int DEF = 25;

    constexpr int REGEN = 5;
    constexpr int ALLERGY_DMG = 5;
    const Race ALLERGIC = Race::Dwarf;

    constexpr double DODGE = 0.5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<Dodge>(std::move(mods), DODGE);

    std::vector<std::unique_ptr<StatsManager>> stman;
    stman.emplace_back(std::make_unique<HealOnHit>(
        REGEN, ALLERGY_DMG, ALLERGIC
    ));

    auto e = std::make_unique<Player>(cell, MAX_HP, HP, ATK, DEF, Race::Vampire, std::move(mods), std::move(stman));
    return e;
}
