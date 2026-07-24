export module potionatkeffect;

import <memory>;
import modifiers;
import potioneffect;
import race;
import statmodifier;

export class PotionAtkEffect: public PotionEffect {
  public:
    PotionAtkEffect(std::unique_ptr<StatModifier> next, int value);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
