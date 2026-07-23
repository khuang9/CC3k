module statsmanager;

void StatsManager::handleOnTurn(Stats &s, Race enemyRace) const {}
void StatsManager::handleOnHit(Stats &s, Race enemyRace) const {}
void StatsManager::handleOnKill(Stats &s, Race enemyRace) const {}

void StatsManager::onTurn(Stats &s, Race enemyRace) const {
    handleOnTurn(s, enemyRace);
}

void StatsManager::onHit(Stats &s, Race enemyRace) const {
    handleOnHit(s, enemyRace);
}

void StatsManager::onKill(Stats &s, Race enemyRace) const {
    handleOnKill(s, enemyRace);
}

StatsManager::~StatsManager() {}