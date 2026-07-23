export module moddecorator;

import <memory>;
import statmodifier;

export class ModDecorator: public StatModifier {
  protected:
    std::unique_ptr<StatModifier> next;
  public:
    ModDecorator(std::unique_ptr<StatModifier> next);
};
