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
import character_and_item;
using namespace std;

int main() {
    Floor f{"emptyfloor.txt"};
    std::cout << f;

    std::unique_ptr<WorldElement> p = f.spawnElement(std::make_unique<ShadeSpawner>(), 5, 5);//new Player{Location{5, 5}, 100, 100, 100, 100, Race::Shade};
    std::unique_ptr<WorldElement> p2 = f.spawnElement(std::make_unique<ShadeSpawner>(), 6, 6);
    std::cout << f;
    while (true) {
        p->takeTurn();
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
