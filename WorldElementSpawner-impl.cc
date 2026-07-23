module worldelementspawner;

WorldElement *WorldElementSpawner::spawn(Cell *cell) const {
    return doSpawn(cell);
}
