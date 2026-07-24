module nonhostile;

import <utility>;

NonHostile::NonHostile(std::unique_ptr<StatModifier> next)
    : PermanentMod{std::move(next)} {}

Modifiers NonHostile::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.neutral = true;
    return m;
}
