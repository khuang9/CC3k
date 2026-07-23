export module lootextra;

import race;
import stats;
import statsmanager;

// import ability;

// export class LootExtra: public Ability {
//     int lootAmount;

//   public:
//     LootExtra(Entity *e, int lootAmount);

//     virtual void kill(Entity *other) override;
// }

export class LootExtra: public StatsManager {
    int lootAmount;

  protected:
    virtual void handleOnKill(Stats &s, Race enemyRace) const override;
  public:
    LootExtra(int lootAmount);
};
