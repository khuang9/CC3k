export module state;

import spatial;

export enum class StateType {
    FloorCompleted,
    PlayerLeaving,
    PlayerArriving,
    CharacterLeaving,
    CharacterArriving,
    CellUpdate,
    PlayerDeath,
    StairsReached
};

export struct State {
    StateType type;
    Location loc;
};
