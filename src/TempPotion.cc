export module temppotion;

import <memory>;
import colour;
import worldelement_and_cell;
import character_and_item;
import potioneffect;

export class TempPotion: public Item {
    std::unique_ptr<PotionEffect> effects;
  protected:
    virtual void doUseOn(Character *c) override;
  public:
    TempPotion(Cell *c, int value, std::unique_ptr<PotionEffect> effects);
};
