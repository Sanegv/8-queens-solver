#include "board_test.h"
#include "solver_test.h"

void allTests(){
    printf("Running all tests...\n");
    allBoardTests();
    allSolverTests();
    printf("All tests passed.\n");
}

int main(){
    allTests();

    return 0;
}