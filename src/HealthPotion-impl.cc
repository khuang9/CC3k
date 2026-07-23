module healthpotion;

HealthPotion::HealthPotion(Cell *c, int value)
    : Item{'P', Colour::Green, c, value} {}

void HealthPotion::doUseOn(Character *c) {
    c->updateHP(value);
}
