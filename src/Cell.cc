export module cell;

import <utility>;
import <vector>;
import spatial;
import state;
import info;
import subjectobserver;
import worldelement;

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
    void attachElement(WorldElement *el);
    void detachElement();
};
