module environmenttile;

EnvironmentTile::EnvironmentTile(char s, Colour c, WorldElementType t, Cell *cell)
    : WorldElement{s, c, t, cell} {}

void EnvironmentTile::doNotify(Subject &whoFrom) {}

Info EnvironmentTile::doGetInfo() const {
    return {};
}

EnvironmentTile::~EnvironmentTile() {}
