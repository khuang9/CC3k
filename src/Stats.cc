export module stats;

export struct Stats {
    int maxHP;
    int hp;
    int atk;
    int def;
    int gold;
    int lifetimeGold;

    Stats(int maxHP, int hp, int atk, int def);
    void updateHP(int amount);
    void updateGold(int amount);
};
