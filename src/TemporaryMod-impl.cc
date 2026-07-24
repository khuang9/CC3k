module temporarymod;

TemporaryMod::TemporaryMod(std::unique_ptr<StatModifier> next)
    : ModDecorator{std::move(next)} {}

std::unique_ptr<StatModifier> TemporaryMod::prune(std::unique_ptr<StatModifier> me) {
    if (next) {
        auto tmp = next.get();
        next = tmp->prune(std::move(next));
    }
    return std::move(next);
}
