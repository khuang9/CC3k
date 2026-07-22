export module environmenttile;

import worldelement;
import colour;
import info;
import worldelementtype;
import spatial;

export class EnvironmentTile: public WorldElement {
    virtual void doNotify(Subject &whoFrom) override;
  protected:
    virtual Info doGetInfo() const override;
  public:
    EnvironmentTile(char s, Colour c, WorldElementType t, const Location &loc);
    virtual ~EnvironmentTile();
};
