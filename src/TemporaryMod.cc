export module temporarymod;

import <memory>;
import moddecorator;
import statmodifier;

export class TemporaryMod: public ModDecorator {
  public:
    TemporaryMod(std::unique_ptr<StatModifier> next);
    virtual std::unique_ptr<StatModifier> prune(std::unique_ptr<StatModifier> me) override;
};
