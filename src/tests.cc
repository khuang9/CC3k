// import shadespawner;
// import player;
// import <iostream>;
// import drowspawner;
// import vampirespawner;
// import goblinspawner;
import <iostream>;
import <memory>;
import floor;
import worldelement_and_cell;
import spatial;
import race;
import shadespawner;
import smallgoldspawner;
import phspawner;
import rhspawner;
import baspawner;
import bdspawner;
import waspawner;
import wdspawner;
import character_and_item;
import dwarfspawner;
import elfspawner;
import vampirespawner;
import trollspawner;
import goblinspawner;
import orcspawner;
import humanspawner;
import halflingspawner;
import merchantspawner;
import drowspawner;
import randomizer;
using namespace std;

int main() {
    Randomizer::setSeed(42);
    Floor f{"emptyfloor.txt"};
    std::cout << f;

    Character *p = dynamic_cast<Character*>(f.spawnPlayer(std::make_unique<DrowSpawner>(), 6, 25));//new Player{Location{5, 5}, 100, 100, 100, 100, Race::Shade};
    WorldElement *p2 = f.spawnElement(std::make_unique<OrcSpawner>(), 6, 28);
    // WorldElement *p3 = f.spawnElement(std::make_unique<MerchantSpawner>(), 6, 20);
    // WorldElement *p4 = f.spawnElement(std::make_unique<SmallGoldSpawner>(), 6, 27);
    WorldElement *p5 = f.spawnElement(std::make_unique<BASpawner>(), 6, 23);
    WorldElement *p6 = f.spawnElement(std::make_unique<WDSpawner>(), 6, 24);
    std::cout << f;
    int i = 0;
    while (true) {
        p->takeTurn();
        p2->takeTurn();
        // p3->takeTurn();
        std::cout << f;
        std::cout << *p;
        std::cout << "Turn: " << i << std::endl;
        if (i == 5) {
            std::cout << "finna prune it" << std::endl;
            p->loseTempEffects();
        }
        // std::cout << *(dynamic_cast<Character*>(p2));
        // std::cout << *(dynamic_cast<Character*>(p3));
        ++i;
    }
    // Player *p2 = new Player{Location{5, 5}, 200, 200, 200, 200, Race::Vampire};
    // std::cout << *p << std::endl;
    // std::cout << *p2 << std::endl;
    // p->doAttack(p2);
    // std::cout << *p2 << std::endl;
    // p2->doAttack(p);
    // std::cout << *p << std::endl;
    // delete p2;
}
