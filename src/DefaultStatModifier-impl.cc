module defaultstatmodifier;

Modifiers DefaultStatModifier::getModifiers(Race enemyRace) const {
    return Modifiers();
}

std::unique_ptr<StatModifier> DefaultStatModifier::prune(std::unique_ptr<StatModifier> me) {
    return std::move(me);
}
