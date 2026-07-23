export module character_and_item;

import <algorithm>;
import <iostream>;
import <memory>;
import <unordered_set>;
import <utility>;
import <vector>;
import colour;
import modifiers;
import race;
import spatial;
import state;
import stats;
import statsmanager;
import statmodifier;
import info;
import worldelement_and_cell;
import worldelementtype;

export class Item;

export class Character: public WorldElement {
  protected:
    Stats stats;
    Race race;
    std::unordered_set<Race> attackedOrKilled;
    // std::unordered_set<PotionType> potionsUsed;
    StateType leavingStateType, arrivingStateType;
    std::unique_ptr<StatModifier> mods;
    std::vector<std::unique_ptr<StatsManager>> statHandlers;

    int calcDamage(Character *attacker);
    void handleHit(Character *other);
    void handleKill(Character *other);
    void handleTurn();

  public:
    virtual void move(Direction direction);
    virtual void doAttack(WorldElement *other);
    virtual void landHit(Character *other);
    virtual void getHit(Character *other);
    virtual void kill(Character *other);
    virtual void die(Character *killedBy) = 0;
    void use(WorldElement *other);

    // virtual void doUpdateGold(int amount);
    // virtual void doUpdateHP(int amount);

    virtual Info doGetInfo() const override;

  public:
    Character(
        char symbol, Colour c, WorldElementType t, Cell *cell,
        int maxHP, int hp, int atk, int def,
        Race race, StateType leave, StateType arrive,
        std::unique_ptr<StatModifier> mods,
        std::vector<std::unique_ptr<StatsManager>> stman);
    Character();
    Modifiers getMods(Race r = Race::None) const;
    double getPotionBoost() const;
    double getScore() const;
    double getModifiedDef() const;
    double getModifiedAtk(Race r) const;
    void updateGold(int amount);
    void updateHP(int amount);

    // void setModifiers(const Modifiers &m);
    virtual ~Character();

    friend std::ostream &operator<<(std::ostream &out, const Character &e);
};

export std::ostream &operator<<(std::ostream &out, const Character &e) {
    out << "Race: " << e.race;
    out << " Gold: " << e.stats.gold << std::endl;
    out << "HP: " << e.stats.hp << std::endl;
    out << "Atk: " << e.stats.atk << std::endl;
    out << "Def: " << e.stats.def << std::endl;
    return out;
}

export class Item: public WorldElement {
  protected:
    int value;
    virtual void doUseOn(Character *c) = 0;
    virtual Info doGetInfo() const override;
  public:
    Item(char symbol, Colour c, Cell *cell, int value);
    void useOn(Character *c);
    virtual ~Item();
};
