module wdspawner;

import <memory>;
import <utility>;
import potiondefeffect;
import potioneffect;
import temppotion;

std::unique_ptr<WorldElement> WDSpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = -5;

    std::unique_ptr<PotionEffect> effects = nullptr;
    effects = std::make_unique<PotionDefEffect>(std::move(effects), VALUE);

    auto e = std::make_unique<TempPotion>(cell, VALUE, std::move(effects));
    return e;
}
