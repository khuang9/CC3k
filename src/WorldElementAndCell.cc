export module worldelement_and_cell;

import <vector>;
import colour;
import spatial;
import state;
import info;
import worldelementtype;
import subjectobserver;

export class Cell;

export class WorldElement: public Subject, public Observer {
  protected:
    char symbol;
    Colour colour;
    WorldElementType type;
    Location loc;
    Cell *currentCell;
    bool markedForDespawn;

    virtual void doNotify(Subject &whoFrom) override;
    virtual bool doCanOccupy(WorldElementType top);
    virtual void doTakeTurn();

  public:
    WorldElement(char s, Colour c, WorldElementType t, Cell *cell);
    char getChar();
    WorldElementType getType();
    bool canOccupy(Cell *cell);
    void takeTurn();
    virtual ~WorldElement();
};

export class Cell: public Subject, public Observer {
    const Location loc;
    std::vector<WorldElement*> elements;
    std::vector<std::vector<Cell*>> neighbours;

    virtual void doNotify(Subject &whoFrom) override;

  protected:
    virtual Info doGetInfo() const override;

  public:
    Cell(int row, int col);
    void setNeighbours(const std::vector<std::vector<Cell*>> &nb);
    Cell *getNeighbour(Direction dir) const;
    const std::vector<WorldElement*> &getElements() const;
    WorldElementType getTopElementType() const;
    void attachElement(WorldElement *el);
    void detachElement();
};
