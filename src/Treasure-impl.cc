module treasure;

Treasure::Treasure(Cell *c, int value)
    : Item{'G', Colour::Yellow, c, value} {}

void Treasure::doUseOn(Character *c) {
    c->updateGold(value);
}
