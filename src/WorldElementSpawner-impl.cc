module worldelementspawner;

WorldElement *WorldElementSpawner::spawn(const Location &loc) const {
    return doSpawn(loc);
}
