module potiondefeffect;

import <utility>;

PotionDefEffect::PotionDefEffect(std::unique_ptr<StatModifier> next, int value)
    : PotionEffect{std::move(next), value} {}

Modifiers PotionDefEffect::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.defBonus += value;
    return m;
}
