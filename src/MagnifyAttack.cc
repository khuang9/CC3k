export module magnifyattack;

import <memory>;
import modifiers;
import permanentmod;
import race;
import statmodifier;

// export class MagnifyAttack: public Ability {
//     double magnifyAmount;
//     Race worksAgainst;

//   public:
//     MagnifyAttack(Entity *e, double magnifyAmount, Race worksAgainst);

//     virtual void attack(Entity *other, double attackBoost) override;
// }

export class MagnifyAttack: public PermanentMod {
    double amount;
    Race worksAgainst;
  public:
    MagnifyAttack(std::unique_ptr<StatModifier> next, double amount, Race worksAgainst);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
