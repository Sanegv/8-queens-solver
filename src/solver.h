#ifndef QUEENS_SOLVER_SOLVER_H
#define QUEENS_SOLVER_SOLVER_H

#include "board.h"

bool solve(board* b, int i);

bool checkPlacement(board* b);

bool checkDiagonals(board* b);

bool checkFiles(board* b);

bool checkRanks(board* b);

bool checkEmpty(board *b, int i, int j);

#endif //QUEENS_SOLVER_SOLVER_H
