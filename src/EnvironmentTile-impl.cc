module environmenttile;

EnvironmentTile::EnvironmentTile(char s, Colour c, WorldElementType t, const Location &loc)
    : WorldElement{s, c, t, loc} {}

void EnvironmentTile::doNotify(Subject &whoFrom) {}

Info EnvironmentTile::doGetInfo() const {
    return {};
}

EnvironmentTile::~EnvironmentTile() {}
