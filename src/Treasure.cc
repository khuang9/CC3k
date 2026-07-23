export module treasure;

import colour;
import worldelement_and_cell;
import character_and_item;

export class Treasure: public Item {
  protected:
    virtual void doUseOn(Character *c) override;
  public:
    Treasure(Cell *c, int value);
};
