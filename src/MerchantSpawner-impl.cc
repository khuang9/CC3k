module merchantspawner;

import <memory>;
import <utility>;
import <vector>;
import defaultstatmodifier;
import drop;
import dropsitems;
import enemy;
import merchanthoardspawner;
import nonhostile;
import statsmanager;
import statmodifier;

std::unique_ptr<WorldElement> MerchantSpawner::doSpawn(Cell *cell) const {
    constexpr int MAX_HP = 30;
    constexpr int ATK = 70;
    constexpr int DEF = 5;

    std::unique_ptr<StatModifier> mods = std::make_unique<DefaultStatModifier>();
    mods = std::make_unique<NonHostile>(std::move(mods));
    mods = std::make_unique<DropsItems>(std::move(mods));

    std::vector<std::unique_ptr<StatsManager>> stman{};

    std::vector<Drop> drops;
    drops.emplace_back(1, std::make_unique<MerchantHoardSpawner>());

    auto e = std::make_unique<Enemy>('M', cell, MAX_HP, MAX_HP, ATK, DEF, Race::Merchant, std::move(mods), std::move(stman), std::move(drops));
    return e;
}
