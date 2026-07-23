module healonturn;

HealOnTurn::HealOnTurn(int healAmount)
    : StatsManager{}, healAmount{healAmount} {}

// HealOnTurn::HealOnTurn(std::unique_ptr<Character> next, int healAmount)
//     : CharacterQuirk{std::move(next)}, healAmount{healAmount} {}

// void HealOnTurn::doTakeTurn() {
//     updateHP(healAmount);
//     next->takeTurn();
// }

void HealOnTurn::handleOnTurn(Stats &s, Race enemyRace) const {
    s.updateHP(healAmount);
}
