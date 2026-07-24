module extrascore;

import <utility>;

ExtraScore::ExtraScore(std::unique_ptr<StatModifier> next, double amount)
    : PermanentMod{std::move(next)}, amount{amount} {}

Modifiers ExtraScore::getModifiers(Race enemyRace) const {
    Modifiers m = (next) ? next->getModifiers(enemyRace) : Modifiers();
    m.scoreMult *= amount;
    return m;
}
