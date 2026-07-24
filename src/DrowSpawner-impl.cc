module drowspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import dodge;
import magnifypotion;
import statsmanager;
import statmodifier;
import player;

std::unique_ptr<WorldElement> DrowSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 150;
    constexpr int ATK = 25;
    constexpr int DEF = 15;

    constexpr double POTION_BOOST = 1.5;
    constexpr double DODGE = 0.5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<Dodge>(std::move(mods), DODGE);
    mods = std::make_unique<MagnifyPotion>(std::move(mods), POTION_BOOST);

    std::vector<std::unique_ptr<StatsManager>> stman;

    auto e = std::make_unique<Player>(cell, MAX_HP, MAX_HP, ATK, DEF, Race::Drow, std::move(mods), std::move(stman));
    return e;
}
