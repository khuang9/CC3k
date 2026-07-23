module moddecorator;

import <utility>;

ModDecorator::ModDecorator(std::unique_ptr<StatModifier> next)
    : next{std::move(next)} {}
