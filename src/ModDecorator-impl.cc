module moddecorator;

import <utility>;

ModDecorator::ModDecorator(std::unique_ptr<StatModifier> next)
    : next{std::move(next)} {}

void ModDecorator::attachTo(std::unique_ptr<StatModifier> other) {
    if (!next) {
        next = std::move(other);
    } else {
        next->attachTo(std::move(other));
    }
}
