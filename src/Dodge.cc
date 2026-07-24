export module dodge;

import <memory>;
import modifiers;
import permanentmod;
import statmodifier;
import race;

// export class Dodge: public Ability {
//     double dodgeChance;

//   public:
//     Dodge(Entity *e, double dodgeChance);

//     virtual void getHit(Entity *other, double damage, double defBoost) override;
// }

export class Dodge: public PermanentMod {
    double dodgeChance;
  public:
    Dodge(std::unique_ptr<StatModifier> next, double dodgeChance);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
