module magnifypotion;

import <utility>;

MagnifyPotion::MagnifyPotion(std::unique_ptr<StatModifier> next, double amount)
    : PermanentMod{std::move(next)}, amount{amount} {}

// MagnifyPotion::MagnifyPotion(Entity *e, double magnifyAmount)
//     : Ability{e}, magnifyAmount{magnifyAmount} {}

// void MagnifyPotion::drinkPotion(Potion *p, double potionBoost) {
//     next->drinkPotion(p, potionBoost * magnifyAmount)
// }

Modifiers MagnifyPotion::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.potionBoost *= amount;
    return m;
}
