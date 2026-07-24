module dropsitems;

import <utility>;

DropsItems::DropsItems(std::unique_ptr<StatModifier> next)
    : PermanentMod{std::move(next)} {}

Modifiers DropsItems::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.dropsItems = true;
    return m;
}
