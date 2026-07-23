export module race;

import <iostream>;

export enum class Race {
    Shade,
    Drow,
    Vampire,
    Troll,
    Goblin,
    Human,
    Dwarf,
    Elf,
    Orc,
    Merchant,
    Dragon,
    Halfling,
    Any,
    None
};

export std::ostream &operator<<(std::ostream &out, Race race);
