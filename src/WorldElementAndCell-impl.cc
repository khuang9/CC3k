module worldelement_and_cell;

import <iostream>;

WorldElement::WorldElement(char s, Colour c, WorldElementType t, Cell *cell)
    : symbol{s}
    , colour{c}
    , type{t}
    , loc{cell->getInfo().loc}
    , currentCell{cell}
    , markedForDespawn{false} {}

WorldElement::WorldElement()
    : symbol{' '}
    , colour{Colour::None}
    , type{WorldElementType::Blank}
    , loc{0, 0}
    , currentCell{nullptr}
    , markedForDespawn{false} {}

char WorldElement::getChar() {
    return symbol;
}

WorldElementType WorldElement::getType() {
    return type;
}

void WorldElement::doNotify(Subject &whoFrom) {}

bool WorldElement::doCanOccupy(WorldElementType top) {
    return true;
}

bool WorldElement::canOccupy(Cell *cell) {
    if (!cell) return false;
    return doCanOccupy(cell->getTopElementType());
}

void WorldElement::doTakeTurn() {}

void WorldElement::takeTurn() {
    doTakeTurn();
}

WorldElement::~WorldElement() {}

Cell::Cell(int row, int col)
    : loc{row, col} {}

void Cell::setNeighbours(const std::vector<std::vector<Cell*>> &nb) {
    neighbours = nb;
}

Cell *Cell::getNeighbour(Direction dir) const {
    return neighbours[1 + dir.dRow][1 + dir.dCol];
}

const std::vector<WorldElement*> &Cell::getElements() const {
    return elements;
}

WorldElementType Cell::getTopElementType() const {
    if (elements.empty() || !elements.back()) return WorldElementType::Blank;
    return elements.back()->getType();
}

Info Cell::doGetInfo() const {
    return {loc, (elements.empty() || !elements.back()) ? ' ' : elements.back()->getChar()};
}

void Cell::attachElement(WorldElement *el) {
    attach(el);
    elements.emplace_back(el);
    // std::cout << "Cell " << loc << " got " << getInfo().occupantChar << std::endl;
    // setState({StateType::CellUpdate, loc});
    // std::cout << "A: " << loc.row << ' ' << loc.col << std::endl;
    // std::cout << observers.size() << std::endl;
    // std::cout << neighbours[1][1] << std::endl;
    // notifyAll();
}

void Cell::detachElement() {
    detachLast();
    elements.pop_back();
    // std::cout << "Cell " << loc << " got " << getInfo().occupantChar << std::endl;
    // setState({StateType::CellUpdate, loc});
    // notifyAll();
}

void Cell::doNotify(Subject &whoFrom) {
    // StateType t = whoFrom.getState().type;
    // if (t == StateType::CellUpdate) return;
    // std::cout << "Cell " << loc << " notified of change at " << whoFrom.getState().loc << std::endl;
    if (whoFrom.getInfo().loc == whoFrom.getState().loc) {
        setState(whoFrom.getState());
        // std::cout << "A: " << loc.row << ' ' << loc.col << std::endl;
        // std::cout << "B: " << whoFrom.getInfo().loc.row << ' ' << whoFrom.getInfo().loc.col << std::endl;
        notifyAll();
    }
}
