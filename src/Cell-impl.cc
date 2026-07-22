module cell;
import <iostream>;

Cell::Cell(int row, int col)
    : loc{row, col} {}

void Cell::setNeighbours(const std::vector<std::vector<Cell*>> &nb) {
    neighbours = nb;
}

Cell *Cell::getNeighbour(Direction dir) const {
    return neighbours[1 + dir.dRow][1 + dir.dCol];
}

Info Cell::doGetInfo() const {
    return {loc, elements.back()->getChar()};
}

void Cell::attachElement(WorldElement *el) {
    attach(el);
    elements.emplace_back(el);
    setState({StateType::CellAttach, loc});
    // std::cout << "A: " << loc.row << ' ' << loc.col << std::endl;
    // std::cout << observers.size() << std::endl;
    // std::cout << neighbours[1][1] << std::endl;
    notifyAll();
}

void Cell::detachElement() {
    detachLast();
    elements.pop_back();
    setState({StateType::CellDetach, loc});
    notifyAll();
}

void Cell::doNotify(Subject &whoFrom) {
    if (whoFrom.getInfo().loc == whoFrom.getState().loc) {
        setState(whoFrom.getState());
        // std::cout << "A: " << loc.row << ' ' << loc.col << std::endl;
        // std::cout << "B: " << whoFrom.getInfo().loc.row << ' ' << whoFrom.getInfo().loc.col << std::endl;
        notifyAll();
    }
}
