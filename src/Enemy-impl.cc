module enemy;

import <algorithm>;
import <iostream>;
import <utility>;
import <vector>;
import colour;
import player;
import randomizer;
import state;

Enemy::Enemy(char symbol, Cell *cell, int maxHP, int hp, int atk, int def, Race race, std::unique_ptr<StatModifier> mods, std::vector<std::unique_ptr<StatsManager>> stman, std::vector<Drop> drops)
    : Character{symbol, Colour::Red, WorldElementType::Enemy, cell, maxHP, hp, atk, def, race, StateType::EnemyLeaving, StateType::EnemyArriving, std::move(mods), std::move(stman)}
    , aggro{false}, drops{std::move(drops)} {}

void Enemy::doTakeTurn() {
    // decide on action and execute
    if (stats.hp == 0) return;
    if (aggro && loc.inNeighbourhood(playerLoc)) {
        Direction d = playerLoc - loc;
        Cell *newCell = currentCell->getNeighbour(d);
        if (Player *p = dynamic_cast<Player*>(newCell->getElements().back())) {
            if (!(getMods().neutral) || p->hasAttackedOrKilled(race)) {
                doAttack(newCell->getElements().back());
                return;
            }
        }
        // for (WorldElement *we : newCell->getElements()) {
        //     doAttack(we);
        // }
    }
    std::vector<Direction> validDirections;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (!(i == 0 && j == 0) && canOccupy(currentCell->getNeighbour({i, j}))) {
                validDirections.emplace_back(i, j);
            }
        }
    }
    if (!validDirections.empty()) {
        // std::shuffle(validDirections.begin(), validDirections.end(), rng);
        // move(validDirections.back());
        size_t i = Randomizer::randomIndex(validDirections.size() - 1);
        move(validDirections[i]);
    }
    handleTurn();
}

const Drop *Enemy::getRandomDrop() const {
    if (drops.empty()) return nullptr;
    size_t i = Randomizer::randomIndex(drops.size() - 1);
    return &drops[i];
}

void Enemy::die(Character *killedBy) {
    killedBy->kill(this);
    // Drop d = /*randomly chosen*/;
    // for (int i = 0; i < d.amount; ++i) {
    //     auto el = d.spawner->spawn(currentCell);
    //     if ((Item *i = dynamic_cast<Item*>(el.get())) && !getMods().dropsItems) {
    //         i->useOn(killedBy);
    //     }
    //     // todo: make cell own the element so it doesn't die when el goes out of scope
    //     else currentCell->attachElement(el.get());

    // }
    // todo: move to some despawn method
    setState({StateType::EnemyDeath, loc});
    notifyAll();
    despawn();
    // dead = true;
}

void Enemy::doNotify(Subject &whoFrom) {
    State fromState = whoFrom.getState();
    if (fromState.type == StateType::PlayerLeaving) {
        if (fromState.loc.inNeighbourhood(loc) && fromState.loc != loc) {
            std::cout << "Must have been the wind" << std::endl;
            aggro = false;
        }
    } else if (fromState.type == StateType::PlayerArriving) {
        if (fromState.loc.inNeighbourhood(loc) && fromState.loc != loc) {
            aggro = true;
            playerLoc = whoFrom.getState().loc;
            std::cout << "Player spotted at " << playerLoc << std::endl;
        }
    }
}

bool Enemy::doCanOccupy(WorldElementType top) {
    return top == WorldElementType::FloorTile;
}

Enemy::~Enemy() {}
