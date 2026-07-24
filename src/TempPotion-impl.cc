module temppotion;

TempPotion::TempPotion(Cell *c, int value, std::unique_ptr<PotionEffect> effects)
    : Item{'P', Colour::Green, c, value}, effects{std::move(effects)} {}

void TempPotion::doUseOn(Character *c) {
    if (effects) {
        effects->magnify(c->getMods().potionBoost);
        c->addMods(std::move(effects));
    }
}
