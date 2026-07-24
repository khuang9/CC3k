export module enemy;

import <memory>;
import <random>;
import <vector>;
import character_and_item;
import drop;
import spatial;
import statsmanager;
import statmodifier;
import subjectobserver;
import race;
import worldelement_and_cell;
import worldelementtype;

export class Enemy: public Character {
    bool aggro;
    Location playerLoc;
    std::vector<Drop> drops;

  public:
    Enemy(char symbol, Cell *cell, int maxHP, int hp, int atk, int def, Race race, std::unique_ptr<StatModifier> mods, std::vector<std::unique_ptr<StatsManager>> stman, std::vector<Drop> drops);
    const Drop *getRandomDrop() const;
    virtual void doTakeTurn() override;
    virtual void die(Character *killedBy) override;
    virtual void doNotify(Subject &whoFrom) override;
    virtual bool doCanOccupy(WorldElementType top) override;
    virtual ~Enemy();
};
