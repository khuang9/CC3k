export module modifiers;

export struct Modifiers {
    double atkMult;
    int atkBonus;
    int defBonus;
    double potionBoost;
    double scoreMult;
    int numAttacks;
    bool stationary;
    double dodgeChance;
    bool dropsItems;
    bool neutral;

    Modifiers();
};
