export module standguard;

import <memory>;
import modifiers;
import permanentmod;
import statmodifier;
import race;

export class StandGuard: public PermanentMod {
  public:
    StandGuard(std::unique_ptr<StatModifier> next);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};