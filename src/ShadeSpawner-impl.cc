module shadespawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import dodge;
import extrascore;
import statsmanager;
import statmodifier;
import player;

std::unique_ptr<WorldElement> ShadeSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 125;
    constexpr int ATK = 25;
    constexpr int DEF = 25;
    constexpr double SCORE_MULT = 1.5;
    constexpr double DODGE = 0.5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<ExtraScore>(std::move(mods), SCORE_MULT);
    mods = std::make_unique<Dodge>(std::move(mods), DODGE);

    std::vector<std::unique_ptr<StatsManager>> stman{};
    auto e = std::make_unique<Player>(cell, MAX_HP, MAX_HP, ATK, DEF, Race::Shade, std::move(mods), std::move(stman));
    return e;
}
