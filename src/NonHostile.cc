export module nonhostile;

import <memory>;
import modifiers;
import permanentmod;
import race;
import statmodifier;

export class NonHostile: public PermanentMod {
  public:
    NonHostile(std::unique_ptr<StatModifier> next);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
