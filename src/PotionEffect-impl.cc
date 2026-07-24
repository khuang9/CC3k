module potioneffect;

PotionEffect::PotionEffect(std::unique_ptr<StatModifier> next, int value)
    : TemporaryMod{std::move(next)}, value{value} {}

void PotionEffect::magnify(double amount) {
    value *= amount;
    if (next) next->magnify(amount);
}
