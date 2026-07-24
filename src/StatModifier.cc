export module statmodifier;

import <memory>;
import modifiers;
import race;

export class StatModifier {
    public:
        virtual Modifiers getModifiers(Race enemyRace) const = 0;
        virtual std::unique_ptr<StatModifier> prune(std::unique_ptr<StatModifier> me) = 0;
        virtual void attachTo(std::unique_ptr<StatModifier> other);
        virtual void magnify(double amount);
        virtual ~StatModifier();
};
