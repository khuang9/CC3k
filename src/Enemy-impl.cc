module enemy;

import <algorithm>;
import <iostream>;
import <vector>;
import colour;
import state;

Enemy::Enemy(char symbol, Cell *cell, int maxHP, int hp, int atk, int def, Race race)
    : Character{symbol, Colour::Red, WorldElementType::Enemy, cell, maxHP, hp, atk, def, race, StateType::EnemyLeaving, StateType::EnemyArriving}
    , aggro{false} {}

void Enemy::doTakeTurn() {
    // decide on action and execute
    if (hp == 0) return;
    if (aggro) {
        Direction d = playerLoc - loc;
        Cell *newCell = currentCell->getNeighbour(d);
        if (!newCell) std::cout << d << std::endl;
        doAttack(newCell->getElements().back());
        // for (WorldElement *we : newCell->getElements()) {
        //     doAttack(we);
        // }
    } else {
        std::vector<Direction> validDirections;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (!(i == 0 && j == 0) && canOccupy(currentCell->getNeighbour({i, j}))) {
                    validDirections.emplace_back(i, j);
                }
            }
        }
        if (!validDirections.empty()) {
            std::shuffle(validDirections.begin(), validDirections.end(), rng);
            move(validDirections.back());
        }
    }
}

void Enemy::die(Character *killedBy) {
    killedBy->kill(this);
    currentCell->detachElement();
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
