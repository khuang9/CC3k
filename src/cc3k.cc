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
    cout << "Please Enter One of the following races for your Character:" << endl;
    cout << "shade|drow|vampire|troll|goblin" << endl;
    string cmd;
    cin >> cmd; 
    if (cin.fail() || cmd.toLower() == "q") {
        cout << "Terminating Program" << endl;
        return;
    } else if (cmd.toLower() == "drow") {
        
    } else if (cmd.toLower() == "vampire") {

    } else if (cmd.toLower() == "troll") {
        
    } else if (cmd.toLower() == "goblin") {
        
    } else {
      unique_ptr<WorldElement> p = f.spawnElement(make_unique<ShadeSpawner>(), 5, 5);
    }
    cout << f;
    while (true) {
        p->takeTurn();
        cout << f;
        cout << *(dynamic_cast<Character*>(p.get()));
    }
}
