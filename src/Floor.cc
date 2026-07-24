export module floor;

import <fstream>;
import <iostream>;
import <memory>;
import <string>;
import <unordered_map>;
import <unordered_set>;
import <vector>;
import chamber;
import subjectobserver;
import worldelementspawner;
import worldelement_and_cell;
import vertwallspawner;
import horizwallspawner;
import doorspawner;
import passagespawner;

export class Floor: public Observer {
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<std::unique_ptr<Cell>>> cells;
    std::vector<Chamber> chambers;
    std::vector<std::unique_ptr<WorldElement>> elements;
    std::unique_ptr<WorldElement> player;
    virtual void doNotify(Subject &whoFrom) override;

    inline static const std::unordered_set<char> NON_CHAMBER_CELLS{
        '-', '|', '+', '#', ' '
    };

    static inline const std::unordered_map<char, Chamber::SpawnerFactory> NON_CHAMBER_SPAWNER_MAP = {
        {'|', [] { return std::make_unique<VertWallSpawner>(); }},
        {'-', [] { return std::make_unique<HorizWallSpawner>(); }},
        {'+', [] { return std::make_unique<DoorSpawner>(); }},
        {'#', [] { return std::make_unique<PassageSpawner>(); }},
    };


    // Location getFreeCell(WorldElement *we) const;
    // void spawnPlayer();
    // void spawnStairs();
    // void spawnEnemies();
    // void spawnPotions();
    // void spawnTreasure();
    // void runTurn();

  public:
    explicit Floor(std::string file);
    void spawnElements();
    WorldElement *spawnPlayer(const std::unique_ptr<WorldElementSpawner> &s, int r, int c);
    WorldElement *spawnElement(const std::unique_ptr<WorldElementSpawner> &s, int r, int c);
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

export std::ostream &operator<<(std::ostream &out, const Floor &f);
