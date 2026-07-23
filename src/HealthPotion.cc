export module healthpotion;

import colour;
import worldelement_and_cell;
import character_and_item;

export class HealthPotion: public Item {
  protected:
    virtual void doUseOn(Character *c) override;
  public:
    HealthPotion(Cell *c, int value);
};
