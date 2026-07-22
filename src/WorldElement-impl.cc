module worldelement;

WorldElement::WorldElement(char s, Colour c, WorldElementType t, const Location &loc)
    : symbol{s}
    , colour{c}
    , type{t}
    , loc{loc}
    , markedForDespawn{false} {}

char WorldElement::getChar() {
    return symbol;
}

WorldElement::~WorldElement() {}
