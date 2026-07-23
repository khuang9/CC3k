export module character_and_item;

import <algorithm>;
import <iostream>;
import <unordered_set>;
import <utility>;
import colour;
import race;
import spatial;
import state;
import info;
import worldelement_and_cell;
import worldelementtype;

export class Item;

export class Character: public WorldElement {
  protected:
    int maxHP;
    int hp;
    int atk;
    int def;
    int gold;
    int lifetimeGold;
    Race race;
    std::unordered_set<Race> attackedOrKilled;
    // std::unordered_set<PotionType> potionsUsed;
    StateType leavingStateType, arrivingStateType;

    int calcDamage(Character *attacker);

  public:
    virtual void decideDirectionAndMove() = 0;
    void move(Direction direction);
    virtual void doAttack(WorldElement *other);
    virtual void landHit(Character *other);
    virtual void getHit(Character *other);
    virtual void updateGold(int amount);
    virtual void updateHP(int amount, Character *attacker = nullptr);
    virtual void kill(Character *other);
    virtual void die(Character *killedBy) = 0;
    virtual void use(WorldElement *other);

    virtual double doGetPotionBoost() const;
    virtual double doGetAtkMultiplier(Race r) const;
    virtual double doGetModifiedAtk() const;
    virtual double doGetModifiedDef() const;
    virtual double doGetScore() const;

    virtual Info doGetInfo() const override;

  public:
    Character(
      char symbol, Colour c, WorldElementType t, Cell *cell,
      int maxHP, int hp, int atk, int def,
      Race race, StateType leave, StateType arrive);
    double getPotionBoost() const;
    double getBoostedAtk(Race r) const;
    double getModifiedDef() const;
    double getScore() const;
    virtual ~Character();

    friend std::ostream &operator<<(std::ostream &out, const Character &e);
};

export std::ostream &operator<<(std::ostream &out, const Character &e) {
    out << "Race: " << e.race;
    out << " Gold: " << e.gold << std::endl;
    out << "HP: " << e.hp << std::endl;
    out << "Atk: " << e.atk << std::endl;
    out << "Def: " << e.def << std::endl;
    return out;
}

export class Item: public WorldElement {
    int value;
  protected:
    virtual void doUseOn(Character *c) = 0;
  public:
    Item(char symbol, Colour c, WorldElementType t, Cell *cell, int value);
    void useOn(Character *c);
};
