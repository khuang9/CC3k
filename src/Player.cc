export module player;

import <algorithm>;
import <iostream>;
import <string>;
import <unordered_map>;
import <utility>;
import colour;
import worldelement_and_cell;
import worldelementtype;
import character_and_item;
import race;
import spatial;
import state;
import subjectobserver;

export class Player: public Character {;
    inline static const std::unordered_map<std::string, Direction> DIRECTION_MAP{
        {"no", {-1, 0}},
        {"so", {1, 0}},
        {"ea", {0, 1}},
        {"we", {0, -1}},
        {"ne", {-1, 1}},
        {"nw", {-1, -1}},
        {"se", {1, 1}},
        {"sw", {1, -1}}
    };

  protected:
    virtual void doTakeTurn() override;
    virtual void die(Character *killedBy) override;
    virtual bool doCanOccupy(WorldElementType top) override;
    virtual void doNotify(Subject &whoFrom) override;
  public:
    Player(Cell *cell, int maxHP, int hp, int atk, int def, Race race);
    virtual ~Player();
};
