module worldelementspawner;

std::unique_ptr<WorldElement> WorldElementSpawner::spawn(Cell *cell) const {
    return doSpawn(cell);
}
