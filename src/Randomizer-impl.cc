module randomizer;

std::default_random_engine Randomizer::engine{
    static_cast<unsigned>(
        std::chrono::steady_clock::now().time_since_epoch().count()
    )
};

void Randomizer::setSeed(unsigned seed) {
    engine.seed(seed);
}

int Randomizer::randomIndex(size_t n) {
    std::uniform_int_distribution<int> dist(0, n);
    return dist(engine);
}

bool Randomizer::coinToss(double proba) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(engine) < proba;
}
