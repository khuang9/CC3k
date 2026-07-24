module statmodifier;

void StatModifier::attachTo(std::unique_ptr<StatModifier> other) {}
void StatModifier::magnify(double amount) {/* ignore by default */}
StatModifier::~StatModifier() {}
