export module permanentmod;

import <memory>;
import moddecorator;
import statmodifier;

export class PermanentMod: public ModDecorator {
  public:
    PermanentMod(std::unique_ptr<StatModifier> next);
    virtual std::unique_ptr<StatModifier> prune(std::unique_ptr<StatModifier> me) override;
};
