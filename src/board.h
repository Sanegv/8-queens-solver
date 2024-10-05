#ifndef QUEENS_SOLVER_BOARD_H
#define QUEENS_SOLVER_BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long bitboard;

typedef struct{
    bitboard queens;
} board;

board* newBoard();

bitboard coordinatesToQueen(int x, int y);

bool changeQueenState(board* b, int x, int y);

void printQueens(board b);

int countQueens(board b);

void freeBoard(board* b);

#endif //QUEENS_SOLVER_BOARD_H
