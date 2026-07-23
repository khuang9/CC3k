module healonhit;

HealOnHit::HealOnHit(int healAmount, int allergyDamage, Race allergic)
    : StatsManager{}, healAmount{healAmount}, allergyDamage{allergyDamage}, allergic{allergic} {}

// HealOnHit::HealOnHit(Entity *e, int healAmount, int allergyDamage, Race allergic)
//     : Ability{e}
//     , healAmount{healAmount}
//     , allergyDamage{allergyDamage}
//     , allergic{allergic} {}

// void HealOnHit::hit(Entity *other) {
//     if (other.race == allergic || allergic == Race::Any) {
//         takeDamage(allergyDamage);
//     } else {
//         heal(healAmount);
//     }
//     next->hit(other);
// }


void HealOnHit::handleOnHit(Stats &s, Race enemyRace) const {
    if (enemyRace == allergic || allergic == Race::Any) {
        s.updateHP(-allergyDamage);
    } else {
        s.updateHP(healAmount);
    }
}
