#include "solver.h"

int main(){
    board* b = newBoard();
    solve(b);
    printQueens(*b);
    freeBoard(b);
}