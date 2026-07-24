export module defaultstatmodifier;

import <memory>;
import modifiers;
import race;
import statmodifier;

export class DefaultStatModifier: public StatModifier {
  public:
    virtual Modifiers getModifiers(Race enemyRace) const override;
    virtual std::unique_ptr<StatModifier> prune(std::unique_ptr<StatModifier> me) override;
};
