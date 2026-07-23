module player;

Player::Player(Cell *cell, int maxHP, int hp, int atk, int def, Race race, std::unique_ptr<StatModifier> mods, std::vector<std::unique_ptr<StatsManager>> stman)
    : Character{'@', Colour::Blue, WorldElementType::Player, cell, maxHP, hp, atk, def, race, StateType::PlayerLeaving, StateType::PlayerArriving, std::move(mods), std::move(stman)} {}

bool Player::doCanOccupy(WorldElementType top) {
    return (
        top == WorldElementType::FloorTile ||
        top == WorldElementType::Item ||
        top == WorldElementType::Stairs ||
        top == WorldElementType::Door ||
        top == WorldElementType::Passage
    );
}

void Player::doTakeTurn() {
    // decide on action and execute
    std::string cmd;
    std::string dir;
    if (std::cin >> cmd) {
        if (cmd == "a" || cmd == "u") {
            if (std::cin >> dir) {
                if (DIRECTION_MAP.contains(dir)) {
                    Direction d = DIRECTION_MAP.at(dir);
                    Cell *newCell = currentCell->getNeighbour(d);
                    for (WorldElement *we : newCell->getElements()) {
                        if (cmd == "a") doAttack(we);
                        else if (cmd == "u") use(we);
                    }
                }
            }
        } else if (DIRECTION_MAP.contains(cmd)) {
            Direction d = DIRECTION_MAP.at(cmd);
            if (canOccupy(currentCell->getNeighbour(d))) move(d);
            else std::cout << "Cannot move " << cmd << std::endl;
        }
    }
    handleTurn();
}

void Player::die(Character *killedBy) {
    std::cout << "Player (" << race << ") was killed" << std::endl;
    currentCell->detachElement();
    setState({StateType::PlayerDeath, loc});
    notifyAll();
}

void Player::doNotify(Subject &whoFrom) {
    State fromState = whoFrom.getState();
    if (fromState.type == StateType::EnemyArriving) {
        if (fromState.loc.inNeighbourhood(loc) && fromState.loc != loc) {
            setState({StateType::PlayerArriving, loc});
            currentCell->getNeighbour(fromState.loc - loc)->notify(*this);
        }
    }
}

Player::~Player() {}
