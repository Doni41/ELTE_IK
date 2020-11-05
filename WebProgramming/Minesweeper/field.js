export const FieldState = {
    REVEALED: 1,
    UNREVEALED: 2,
    FLAGGED: 4
};

export class Field {
    isMine = false;                 // init with isMine false
    isBlownUp = false               // init with isBlownUp false
    state = FieldState.UNREVEALED;  // init with unrevield
    neighborCount = 0;              // init with 0 neighbour
}