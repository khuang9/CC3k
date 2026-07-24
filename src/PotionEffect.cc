export module potioneffect;

import <memory>;
import temporarymod;
import statmodifier;

export class PotionEffect: public TemporaryMod {
  protected:
    int value;
  public:
    PotionEffect(std::unique_ptr<StatModifier> next, int value);
    virtual void magnify(double amount) override;
};
