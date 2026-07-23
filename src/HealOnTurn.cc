export module healonturn;

import race;
import stats;
import statsmanager;

// import <memory>;
// import characterquirk;

// export class HealOnTurn: public CharacterQuirk {
//     int healAmount;
//   public:
//     HealOnTurn(std::unique_ptr<Character> next, int healAmount);

//     virtual void doTakeTurn() override;
// };

export class HealOnTurn: public StatsManager {
    int healAmount;

  protected:
    virtual void handleOnTurn(Stats &s, Race enemyRace) const override;
  public:
    HealOnTurn(int healAmount);
};
