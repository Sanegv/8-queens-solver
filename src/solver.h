#ifndef QUEENS_SOLVER_SOLVER_H
#define QUEENS_SOLVER_SOLVER_H

#include "board.h"

void solve(board* b);

bool checkPlacement(board* b);

bool checkDiagonals(board* b);

bool checkFiles(board* b);

bool checkRanks(board* b);

#endif //QUEENS_SOLVER_SOLVER_H
