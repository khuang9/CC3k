module dodge;

import <utility>;

Dodge::Dodge(std::unique_ptr<StatModifier> next, double dodgeChance)
    : PermanentMod{std::move(next)}, dodgeChance{dodgeChance} {}

// Dodge::Dodge(Entity *e, double dodgeChance)
//     : Ability{e}, dodgeChance{dodgeChance} {}

// void Dodge::getHit(Entity *other, double damage, double defBoost) {
//     if (!(/*dodgeChance hits*/)) {
//         next->getHit(other, damage, defBoost);
//     }
// }

Modifiers Dodge::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    // 1 - (1 - p)(1 - q) = 1 - (1 - q - p + pq) = p + q - pq
    m.dodgeChance = m.dodgeChance + dodgeChance - m.dodgeChance * dodgeChance;
    return m;
}
