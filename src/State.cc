export module state;

import spatial;

export enum class StateType {
    FloorCompleted,
    PlayerLeaving,
    PlayerArriving,
    EnemyLeaving,
    EnemyArriving,
    CellUpdate,
    PlayerDeath,
    StairsReached,
    DontCare
};

export struct State {
    StateType type;
    Location loc;
};
