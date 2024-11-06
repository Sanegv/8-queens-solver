#include "solver.h"

int main(){
    board* b = newBoard();
    solve(b, 0);
    printQueens(*b);
    freeBoard(b);
}