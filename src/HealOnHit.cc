export module healonhit;

import stats;
import statsmanager;
import race;

// export class HealOnHit: public Ability {
//     int healAmount;
//     int allergyDamage;
//     Race allergic;

//   public:
//     HealOnHit(Entity *e, int healAmount, int allergyDamage, Race allergic);

//     virtual void hit(Entity *other) override;
// }

export class HealOnHit: public StatsManager {
    int healAmount;
    int allergyDamage;
    Race allergic;

  protected:
    virtual void handleOnHit(Stats &s, Race enemyRace) const override;
  public:
    HealOnHit(int healAmount, int allergyDamage, Race allergic);
};
