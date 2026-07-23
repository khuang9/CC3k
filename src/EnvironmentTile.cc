export module environmenttile;

import worldelement_and_cell;
import colour;
import info;
import worldelementtype;
import spatial;

export class EnvironmentTile: public WorldElement {
    virtual void doNotify(Subject &whoFrom) override;
  protected:
    virtual Info doGetInfo() const override;
  public:
    EnvironmentTile(char s, Colour c, WorldElementType t, Cell *cell);
    virtual ~EnvironmentTile();
};
