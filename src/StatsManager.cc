export module statsmanager;

import stats;
import race;

export class StatsManager {
  protected:
    virtual void handleOnTurn(Stats &s, Race enemyRace) const;
    virtual void handleOnHit(Stats &s, Race enemyRace) const;
    virtual void handleOnKill(Stats &s, Race enemyRace) const;

  public:
    void onTurn(Stats &s, Race enemyRace) const;
    void onHit(Stats &s, Race enemyRace) const;
    void onKill(Stats &s, Race enemyRace) const;
    virtual ~StatsManager();
};
