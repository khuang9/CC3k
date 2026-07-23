module stats;

import <algorithm>;

Stats::Stats(int maxHP, int hp, int atk, int def)
    : maxHP{maxHP}, hp{hp}, atk{atk}, def{def}, gold{0}, lifetimeGold{0} {}

void Stats::updateHP(int amount) {
    hp = std::clamp(hp + amount, 0, maxHP);
}

void Stats::updateGold(int amount) {
    gold = std::max(gold + amount, 0);
    if (amount > 0) lifetimeGold += amount;
}
