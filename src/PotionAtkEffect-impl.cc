module potionatkeffect;

import <utility>;

PotionAtkEffect::PotionAtkEffect(std::unique_ptr<StatModifier> next, int value)
    : PotionEffect{std::move(next), value} {}

Modifiers PotionAtkEffect::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.atkBonus += value;
    return m;
}
