export module defaultstatmodifier;

import modifiers;
import race;
import statmodifier;

export class DefaultStatModifier: public StatModifier {
  public:
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
