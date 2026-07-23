module character_and_item;

import <cmath>;

Character::Character(
    char symbol, Colour c, WorldElementType t, Cell *cell,
    int maxHP, int hp, int atk, int def,
    Race race, StateType leave, StateType arrive)
    : WorldElement{symbol, c, t, cell}
    , maxHP{maxHP}
    , hp{hp}
    , atk{atk}
    , def{def}
    , gold{0}
    , lifetimeGold{0}
    , race{race}
    , leavingStateType{leave}
    , arrivingStateType{arrive} {}

Character::Character()
    : WorldElement{}
    , maxHP{0}
    , hp{0}
    , atk{0}
    , def{0}
    , gold{0}
    , lifetimeGold{0}
    , race{Race::None}
    , leavingStateType{StateType::DontCare}
    , arrivingStateType{StateType::DontCare} {}

int Character::calcDamage(Character *attacker) {
    constexpr int BALANCE = 100;
    return std::ceil((BALANCE / (BALANCE + getModifiedDef())) * attacker->getBoostedAtk(race));
}

void Character::move(Direction dir) {
    setState({leavingStateType, loc});
    std::cout << race << " moved from " << loc << " to " << loc + dir << std::endl;
    currentCell->notify(*this);
    loc = loc + dir;
    currentCell->detachElement();
    currentCell = currentCell->getNeighbour(dir);
    currentCell->attachElement(this);
    setState({arrivingStateType, loc});
    currentCell->notify(*this);
}

void Character::doAttack(WorldElement *other) {
    //note to self: attacking enemy prints twice since attacks floor underneath first
    std::cout << race << " is attacking" << std::endl;
    if (Character *c = dynamic_cast<Character*>(other)) {
        c->getHit(this);
    } else {
        std::cout << race << " did not hit anything" << std::endl;
    }
}

void Character::landHit(Character *other) {
    std::cout << race << " landed a hit on " << other->race << std::endl;
    // Default: no on-hit effects
    // Decorators to add on-hit effects as needed
}

void Character::getHit(Character *other) {
    double dmg = calcDamage(other);
    std::cout << race << " is hit by " << other->race << std::endl;
    updateHP(-dmg);
    if (hp == 0) die(other);
}

void Character::doUpdateGold(int amount) {
    std::cout << race << " gained " << amount << " gold" << std::endl;
    gold = std::max(0, gold + amount);
    if (amount > 0) lifetimeGold += amount;
}

void Character::doUpdateHP(int amount) {
    if (amount < 0) std::cout << race << " took " << -amount << " damage ";
    else std::cout << race << " healed " << amount << " hp ";
    std::cout << "(" << hp << " -> ";
    hp = std::max(0, std::min(maxHP, hp + amount));
    std::cout << hp << ")" << std::endl;
}

void Character::updateGold(int amount) {
    doUpdateGold(amount);
}

void Character::updateHP(int amount) {
    doUpdateHP(amount);
}

void Character::kill(Character *other) {
    std::cout << race << " has killed a " << other->race;
    // Default: no on-kill effects
    // Decorators to add on-kill effects as needed
}

void Character::use(WorldElement *other) {
    if (Item *i = dynamic_cast<Item*>(other)) {
        Direction d = i->getInfo().loc - loc;
        i->useOn(this);
        move(d);
    }
}

double Character::doGetPotionBoost() const {
    constexpr double DEFAULT_BOOST = 1.0;
    return DEFAULT_BOOST;
}

double Character::doGetAtkMultiplier(Race r) const {
    constexpr double DEFAULT_MULTIPLIER = 1.0;
    return DEFAULT_MULTIPLIER;
}

double Character::doGetModifiedAtk() const {
    return atk;
}

double Character::doGetModifiedDef() const {
    return def;
}

double Character::doGetScore() const {
    return lifetimeGold;
}

double Character::getPotionBoost() const {
    return doGetPotionBoost();
}

double Character::getBoostedAtk(Race r) const {
    return doGetModifiedAtk() * doGetAtkMultiplier(r);
}

double Character::getModifiedDef() const {
    return doGetModifiedDef();
}

double Character::getScore() const {
    return doGetScore();
}

Info Character::doGetInfo() const {
    return {loc, symbol};
}

Character::~Character() {}

Item::Item(char symbol, Colour c, Cell *cell, int value)
    : WorldElement{symbol, c, WorldElementType::Item, cell}
    , value{value} {}

void Item::useOn(Character *c) {
    doUseOn(c);
    currentCell->detachElement();
}

Info Item::doGetInfo() const {
    return {loc, symbol};
}

Item::~Item() {}
