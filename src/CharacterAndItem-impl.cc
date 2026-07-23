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
    if (Character *c = dynamic_cast<Character*>(other)) {
        std::cout << race << " is attacking" << std::endl;
        c->getHit(this);
    }
}

void Character::landHit(Character *other) {
    // Default: no on-hit effects
    // Decorators to add on-hit effects as needed
}

void Character::getHit(Character *other) {
    double dmg = calcDamage(other);
    std::cout << race << " is hit for " << dmg << std::endl;
    updateHP(-dmg, other);
}

void Character::updateGold(int amount) {
    gold = std::max(0, gold + amount);
    if (amount > 0) lifetimeGold += amount;
}

void Character::updateHP(int amount, Character *attacker) {
    std::cout << race << "'s hp went from " << hp << " to ";
    hp = std::max(0, std::min(maxHP, hp + amount));
    std::cout << hp << std::endl;
    if (hp == 0) die(attacker);
}

void Character::kill(Character *other) {
    std::cout << race << " has killed a " << other->race;
    // Default: no on-kill effects
    // Decorators to add on-kill effects as needed
}

void Character::use(WorldElement *other) {}

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

void Character::takeTurn() {
    doTakeTurn();
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

Item::Item(char symbol, Colour c, WorldElementType t, Cell *cell, int value)
    : WorldElement{symbol, c, t, cell}
    , value{value} {}

void Item::useOn(Character *c) {
    doUseOn(c);
}
