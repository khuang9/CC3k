module lootextra;

LootExtra::LootExtra(int lootAmount)
    : StatsManager{}, lootAmount{lootAmount} {}

// LootExtra::LootExtra(Entity *e, int lootAmount)
//     : Ability{e}, lootAmount{lootAmount} {}

// void LootExtra::kill(Entity *other) {
//     gainGold(lootAmount);
//     next->kill(other);
// }

void LootExtra::handleOnKill(Stats &s, Race enemyRace) const {
    s.updateGold(lootAmount);
}