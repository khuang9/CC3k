export module randomizer;

import <algorithm>;
import <chrono>;
import <random>;
import <vector>;

export class Randomizer {
    static std::default_random_engine engine;

  public:
    static void setSeed(unsigned seed);

    static int randomIndex(size_t n);
    static bool coinToss(double proba);
};
