module magnifyattack;

import <utility>;

MagnifyAttack::MagnifyAttack(std::unique_ptr<StatModifier> next, double amount, Race worksAgainst)
    : PermanentMod{std::move(next)}, amount{amount}, worksAgainst{worksAgainst} {}

// MagnifyAttack::MagnifyAttack(Entity *e, double magnifyAmount, Race worksAgainst)
//     : Ability{e}, magnifyAmount{magnifyAmount}, worksAgainst{worksAgainst} {}

// void MagnifyAttack::attack(Entity *other, double attackBoost) {
//     if (other.race == worksAgainst || worksAgainst == Race::Any) {
//         next->attack(other, attackBoost * magnifyAmount);
//     } else {
//         next->attack(other, attackBoost);
//     }
// }

Modifiers MagnifyAttack::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    if (enemyRace == worksAgainst || worksAgainst == Race::Any) {
        m.atkMult *= amount;
    }
    return m;
}
