export module multiattack;

// import ability;
import <memory>;
import modifiers;
import permanentmod;
import race;
import statmodifier;

// export class MultiAttack: public Ability {
//     int attackTimes;
//     Race exception;

//   public:
//     HealOnTurn(Entity *e, int attackTimes, Race exception);

//     virtual void attack(Entity *other, double attackBoost) override;
// }

export class MultiAttack: public PermanentMod {
    int numAttacks;
    Race exception;
  public:
    MultiAttack(std::unique_ptr<StatModifier> next, int numAttacks, Race exception);
    virtual Modifiers getModifiers(Race enemyRace) const override;
};
