export module extrascore;

import <memory>;
import moddecorator;
import modifiers;
import permanentmod;
import race;
import statmodifier;

export class ExtraScore: public PermanentMod {
    double amount;
  public:
    ExtraScore(std::unique_ptr<StatModifier> next, double amount);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
