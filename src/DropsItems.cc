export module dropsitems;

import <memory>;
import moddecorator;
import modifiers;
import permanentmod;
import race;
import statmodifier;

export class DropsItems: public PermanentMod {
  public:
    DropsItems(std::unique_ptr<StatModifier> next);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
