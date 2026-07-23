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
import character_and_item;
import dwarfspawner;
import elfspawner;
import vampirespawner;
import trollspawner;
import goblinspawner;
using namespace std;

int main() {
    Floor f{"emptyfloor.txt"};
    std::cout << f;

    std::unique_ptr<WorldElement> p = f.spawnElement(std::make_unique<GoblinSpawner>(), 6, 25);//new Player{Location{5, 5}, 100, 100, 100, 100, Race::Shade};
    std::unique_ptr<WorldElement> p2 = f.spawnElement(std::make_unique<DwarfSpawner>(), 6, 28);
    // std::unique_ptr<WorldElement> p3 = f.spawnElement(std::make_unique<SmallGoldSpawner>(), 5, 7);
    // std::unique_ptr<WorldElement> p4 = f.spawnElement(std::make_unique<PHSpawner>(), 5, 8);
    // std::unique_ptr<WorldElement> p5 = f.spawnElement(std::make_unique<RHSpawner>(), 5, 9);
    std::cout << f;
    while (true) {
        p->takeTurn();
        p2->takeTurn();
        std::cout << f;
        std::cout << *(dynamic_cast<Character*>(p.get()));
        std::cout << *(dynamic_cast<Character*>(p2.get()));
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
