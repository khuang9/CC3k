module standguard;

import <utility>;

StandGuard::StandGuard(std::unique_ptr<StatModifier> next)
    : PermanentMod{std::move(next)} {}

Modifiers StandGuard::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.stationary = true;
    return m;
}
