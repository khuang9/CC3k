module multiattack;

import <utility>;

MultiAttack::MultiAttack(std::unique_ptr<StatModifier> next, int numAttacks, Race exception)
    : ModDecorator{std::move(next)}, numAttacks{numAttacks}, exception{exception} {}

// MultiAttack::MultiAttack(Entity *e, int attackTimes, Race exception)
    // : Ability{e}, attackTimes{attackTimes}, exception{exception} {}

// void MultiAttack::attack(Entity *other, double attackBoost) {
//     if (other.race != exception || exception == Race::None) {
//         for (int i = 0; i < attackTimes; ++i) {
//             next->attack(other, attackBoost);
//         }
//     } else {
//         next->attack(other, attackBoost);
//     }
// }

Modifiers MultiAttack::getModifiers(Race enemyRace) const {
    Modifiers m = next->getModifiers(enemyRace);
    if (enemyRace != exception && exception != Race::Any) {
        m.numAttacks *= numAttacks;
    }
    return m;
}
