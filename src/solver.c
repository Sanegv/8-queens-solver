#include "solver.h"

void solve(board *b){
    //TODO
}

bool checkPlacement(board* b){
    if(b == NULL)
        return false;

    return checkDiagonals(b) && checkFiles(b) && checkRanks(b);
}

bool checkDiagonals(board *b){
    bitboard mask = 0x8040201008040201, reverseMask = mask;
    bitboard antiMask = 0x102040810204080, reverseAntiMask = antiMask;
    for(int i = 0; i < 7; i ++){
        if(
            (countQueens((board){mask               & b->queens}) > 1) ||
            (countQueens((board){reverseMask        & b->queens}) > 1) ||
            (countQueens((board){antiMask           & b->queens}) > 1) ||
            (countQueens((board){reverseAntiMask    & b->queens}) > 1)
        )
            return false;
        mask >>= 8;             // up & right
        antiMask <<= 8;         // down & right
        reverseMask <<= 8;      // down & left
        reverseAntiMask >>= 8;  // up & left
    }
    return true;
}

bool checkRanks(board* b){
    if(b == NULL)
        return false;

    bitboard mask = 0xff; //first rank (row)
    for(int i = 0; i < 8; i++){
        if(countQueens((board){b->queens & mask}) > 1)
            return false;
        mask <<= 8;
    }

    return true;
}

bool checkFiles(board* b){
    if(b == NULL)
        return false;

    bitboard mask = 0x101010101010101; //first file (column)
    for(int i = 0; i < 8; i++){
        if(countQueens((board){b->queens & mask}) > 1)
            return false;
        mask <<= 1;
    }

    return true;
}