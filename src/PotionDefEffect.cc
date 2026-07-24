export module potiondefeffect;

import <memory>;
import modifiers;
import potioneffect;
import race;
import statmodifier;

export class PotionDefEffect: public PotionEffect {
  public:
    PotionDefEffect(std::unique_ptr<StatModifier> next, int value);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
