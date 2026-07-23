// import shadespawner;
// import player;
// import <iostream>;
// import drowspawner;
// import vampirespawner;
// import goblinspawner;
import <iostream>;
import <memory>;
import floor;
import player;
import spatial;
import race;
import shadespawner;
using namespace std;

int main() {
    Floor f{"emptyfloor.txt"};
    std::cout << f;

    Player *p = static_cast<Player*>(f.spawnElement(std::make_unique<ShadeSpawner>(), 5, 5));//new Player{Location{5, 5}, 100, 100, 100, 100, Race::Shade};
    std::cout << f;
    while (true) {
        p->takeTurn();
        std::cout << f;
    }
    // Player *p2 = new Player{Location{5, 5}, 200, 200, 200, 200, Race::Vampire};
    // std::cout << *p << std::endl;
    // std::cout << *p2 << std::endl;
    // p->doAttack(p2);
    // std::cout << *p2 << std::endl;
    // p2->doAttack(p);
    // std::cout << *p << std::endl;
    delete p;
    // delete p2;
}
