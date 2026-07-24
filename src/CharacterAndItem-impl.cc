module character_and_item;

import <cmath>;
import randomizer;
// import potion;

Character::Character(
    char symbol, Colour c, WorldElementType t, Cell *cell,
    int maxHP, int hp, int atk, int def,
    Race race, StateType leave, StateType arrive,
    std::unique_ptr<StatModifier> mods,
    std::vector<std::unique_ptr<StatsManager>> stman)
    : WorldElement{symbol, c, t, cell}
    , stats{maxHP, hp, atk, def}
    , race{race}
    , leavingStateType{leave}
    , arrivingStateType{arrive}
    , mods{std::move(mods)}
    , statHandlers{std::move(stman)} {}

Character::Character()
    : WorldElement{}
    , stats{0, 0, 0, 0}
    , race{Race::None}
    , leavingStateType{StateType::DontCare}
    , arrivingStateType{StateType::DontCare}
    , mods{}
    , statHandlers{} {}

int Character::calcDamage(Character *attacker) {
    constexpr int BALANCE = 100;
    return std::ceil((BALANCE / (BALANCE + getModifiedDef())) * attacker->getModifiedAtk(race));
}

void Character::move(Direction dir) {
    if (getMods().stationary) return;
    setState({leavingStateType, loc});
    std::cout << race << " moved from " << loc << " to " << loc + dir << std::endl;
    currentCell->notify(*this);
    loc = loc + dir;
    currentCell->detachElement(this);
    currentCell = currentCell->getNeighbour(dir);
    currentCell->attachElement(this);
    setState({arrivingStateType, loc});
    currentCell->notify(*this);
}

void Character::doAttack(WorldElement *other) {
    //note to self: attacking enemy prints twice since attacks floor underneath first
    std::cout << race << " is attacking" << std::endl;
    if (Character *c = dynamic_cast<Character*>(other)) {
        for (int i = 0; i < getMods(c->race).numAttacks; ++i) {
            attackedOrKilled.emplace(c->race);
            c->getHit(this);
        }
    } else {
        std::cout << race << " did not hit anything" << std::endl;
    }
}

void Character::handleHit(Character *other) {
    for (const auto &h : statHandlers) {
        h->onHit(stats, other->race);
    }
}

void Character::handleKill(Character *other) {
    for (const auto &h : statHandlers) {
        h->onKill(stats, other->race);
    }
}

void Character::handleTurn() {
    for (const auto &h : statHandlers) {
        h->onTurn(stats, Race::None);
    }
}

void Character::landHit(Character *other) {
    std::cout << race << " landed a hit on " << other->race << std::endl;
    handleHit(other);
    // Default: no on-hit effects
    // Decorators to add on-hit effects as needed
}

void Character::getHit(Character *other) {
    // todo: chance to dodge
    if (Randomizer::coinToss(getMods().dodgeChance)) {
        std::cout << race << " dodged attack from " << other->race << std::endl;
    } else {
        std::cout << race << " could not dodge (this bum has " << getMods().dodgeChance << " to dodge)" << std::endl;
        double dmg = calcDamage(other);
        std::cout << race << " is hit by " << other->race << " (-" << dmg << ")" << std::endl;
        updateHP(-dmg, other);
        other->landHit(this);
    }
}

Race Character::getRace() const {
    return race;
}

// void Character::doUpdateGold(int amount) {
//     std::cout << race << " gained " << amount << " gold" << std::endl;
//     gold = std::max(0, gold + amount);
//     if (amount > 0) lifetimeGold += amount;
// }

// void Character::doUpdateHP(int amount) {
//     if (amount < 0) std::cout << race << " took " << -amount << " damage ";
//     else std::cout << race << " healed " << amount << " hp ";
//     std::cout << "(" << hp << " -> ";
//     hp = std::max(0, std::min(maxHP, hp + amount));
//     std::cout << hp << ")" << std::endl;
// }

void Character::updateGold(int amount) {
    stats.updateGold(amount);
}

void Character::updateHP(int amount, Character *other) {
    stats.updateHP(amount);
    if (stats.hp == 0) die(other);
}

void Character::kill(Character *other) {
    std::cout << race << " has killed " << other->race << std::endl;
    attackedOrKilled.insert(other->race);
    handleKill(other);
    // Default: no on-kill effects
    // Decorators to add on-kill effects as needed
}

void Character::use(WorldElement *other) {
    if (Item *i = dynamic_cast<Item*>(other)) {
        // if (Potion *p = dynamic_cast<Potion*>(i)) p->magnify(getMods().potionBoost);
        i->useOn(this);
    }
}

bool Character::hasAttackedOrKilled(Race r) {
    return attackedOrKilled.contains(r);
}

void Character::loseTempEffects() {
    auto tmp = mods.get();
    mods = tmp->prune(std::move(mods));
}

Modifiers Character::getMods(Race r) const {
    return mods->getModifiers(r);
}

void Character::addMods(std::unique_ptr<StatModifier> newMods) {
    if (newMods) {
        newMods->attachTo(std::move(mods));
        mods = std::move(newMods);
    }
}

double Character::getPotionBoost() const {
    return getMods().potionBoost;
}

double Character::getModifiedAtk(Race r) const {
    Modifiers m = getMods(r);
    return std::max(0, stats.atk + m.atkBonus) * m.atkMult;
}

double Character::getModifiedDef() const {
    return std::max(0, stats.def + getMods().defBonus);
}

double Character::getScore() const {
    return stats.lifetimeGold * getMods().scoreMult;
}

Info Character::doGetInfo() const {
    return {loc, symbol};
}

// void Character::setModifiers(const Modifiers &m) {
//     mods = m;
// }

Character::~Character() {}

Item::Item(char symbol, Colour c, Cell *cell, int value)
    : WorldElement{symbol, c, WorldElementType::Item, cell}
    , value{value} {}

void Item::useOn(Character *c) {
    doUseOn(c);
    despawn();
}

Info Item::doGetInfo() const {
    return {loc, symbol};
}

Item::~Item() {}

std::ostream &operator<<(std::ostream &out, const Character &e) {
    out << "Race: " << e.race;
    out << " Gold: " << e.stats.gold << std::endl;
    out << "HP: " << e.stats.hp << std::endl;
    out << "Atk: " << e.getModifiedAtk() << std::endl;
    out << "Def: " << e.getModifiedDef() << std::endl;
    return out;
}
