module baspawner;

import <memory>;
import <utility>;
import potionatkeffect;
import potioneffect;
import temppotion;

std::unique_ptr<WorldElement> BASpawner::doSpawn(Cell *cell) const {
    constexpr int VALUE = 5;

    std::unique_ptr<PotionEffect> effects = nullptr;
    effects = std::make_unique<PotionAtkEffect>(std::move(effects), VALUE);

    auto e = std::make_unique<TempPotion>(cell, VALUE, std::move(effects));
    return e;
}
