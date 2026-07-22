export module state;

import spatial;

export enum class StateType {
    FloorCompleted,
    PlayerLeaving,
    PlayerArriving,
    CharacterLeaving,
    CharacterArriving,
    CellAttach,
    CellDetach
};

export struct State {
    StateType type;
    Location loc;
};
