module permanentmod;

import <utility>;

PermanentMod::PermanentMod(std::unique_ptr<StatModifier> next)
    : ModDecorator{std::move(next)} {}

std::unique_ptr<StatModifier> PermanentMod::prune(std::unique_ptr<StatModifier> me) {
    if (next) {
        auto tmp = next.get();
        next = tmp->prune(std::move(next));
    }
    return std::move(me);
}
