export module magnifypotion;

import <memory>;
import modifiers;
import permanentmod;
import statmodifier;
import race;

// export class MagnifyPotion: public Ability {
//     double magnifyAmount;

//   public:
//     MagnifyPotion(Entity *e, double magnifyAmount);

//     virtual void drinkPotion(Potion *p, double potionBoost) override;
// }

export class MagnifyPotion: public PermanentMod {
    double amount;
  public:
    MagnifyPotion(std::unique_ptr<StatModifier> next, double amount);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
