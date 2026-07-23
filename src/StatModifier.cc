export module statmodifier;

import modifiers;
import race;

export class StatModifier {
    public:
        virtual Modifiers getModifiers(Race enemyRace) const = 0;
        virtual ~StatModifier();
};
