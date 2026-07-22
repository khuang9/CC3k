export module worldelement;

import colour;
import spatial;
import worldelementtype;
import subjectobserver;

export class WorldElement: public Subject, public Observer {
    char symbol;
    Colour colour;
    WorldElementType type;
    Location loc;
    bool markedForDespawn;

  public:
    WorldElement(char s, Colour c, WorldElementType t, const Location &loc);
    char getChar();
    virtual ~WorldElement();
};
