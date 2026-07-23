export module enemy;

import <random>;
import character_and_item;
import spatial;
import subjectobserver;
import race;
import worldelement_and_cell;
import worldelementtype;

export class Enemy: public Character {
    bool aggro;
    Location playerLoc;
    std::default_random_engine rng{42};

  public:
    Enemy(char symbol, Cell *cell, int maxHP, int hp, int atk, int def, Race race);
    virtual void doTakeTurn() override;
    virtual void die(Character *killedBy) override;
    virtual void doNotify(Subject &whoFrom) override;
    virtual bool doCanOccupy(WorldElementType top) override;
    virtual ~Enemy();
};
