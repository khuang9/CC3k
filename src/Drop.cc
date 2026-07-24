export module drop;

import <memory>;
import worldelementspawner;

export struct Drop {
    int amount;
    std::unique_ptr<WorldElementSpawner> spawner;
};
