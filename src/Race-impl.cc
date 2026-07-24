module race;

std::ostream &operator<<(std::ostream &out, Race race) {
    if (race == Race::Shade) out << "Shade";
    if (race == Race::Drow) out << "Drow";
    if (race == Race::Vampire) out << "Vampire";
    if (race == Race::Troll) out << "Troll";
    if (race == Race::Goblin) out << "Goblin";
    if (race == Race::Human) out << "Human";
    if (race == Race::Dwarf) out << "Dwarf";
    if (race == Race::Elf) out << "Elf";
    if (race == Race::Orc) out << "Orc";
    if (race == Race::Dragon) out << "Dragon";
    if (race == Race::Merchant) out << "Merchant";
    if (race == Race::Halfling) out << "Halfling";

    return out;
}
