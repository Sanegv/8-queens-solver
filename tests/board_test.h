#ifndef QUEENS_SOLVER_BOARD_TEST_H
#define QUEENS_SOLVER_BOARD_TEST_H

#include <assert.h>
#include "src/board.h"

void testNewBoard(){
    printf("Running newBoard() tests... ");
    board* test;
    assert((test = newBoard()) != NULL && "Board allocation failed.");
    bitboard testQueens = test->queens;
    free(test);
    assert(testQueens == 0 && "Board was not empty after initialisation.");
    printf("Passed.\n");
}

void testCoordinatesToQueen(){
    printf("Running coordinatesToQueen() tests... ");
    bitboard expected;
    assert(
            (coordinatesToQueen(8, 0)) == 0 && "Should not be able to have x >= 8"
    );
    assert(
            (coordinatesToQueen(0, 8)) == 0 && "Should not be able to have y >= 8"
    );
    assert(
            (coordinatesToQueen(-1, 0)) == 0 && "Should not be able to have x < 0"
    );
    assert(
            (coordinatesToQueen(0, -1)) == 0 && "Should not be able to have y < 0"
    );
    expected = 0x8000000000000000;
    assert(coordinatesToQueen(7, 7) == expected && "Position to queen does not match.");
    printf("Passed.\n");
}

void testChangeQueenState(){
    printf("Running changeQueenState() tests... ");

    board test = {0};
    board expected = {0x8000000000000000};
    assert(
            (changeQueenState(&test, 8, 0)) == 0 && "Should not be able to have x > 8"
    );
    assert(test.queens == 0 && "changeQueenState modified bitboard despite invalid coordinates. (x >= 8)");
    assert(
            (changeQueenState(&test, 0, 8)) == 0 && "Should not be able to have y >= 8"
    );
    assert(test.queens == 0 && "changeQueenState modified bitboard despite invalid coordinates. (y >= 8)");
    assert(
            (changeQueenState(&test, -1, 0)) == 0 && "Should not be able to have x < 0"
    );
    assert(test.queens == 0 && "changeQueenState modified bitboard despite invalid coordinates. (x < 0)");
    assert(
            (changeQueenState(&test, 0, -1)) == 0 && "Should not be able to have y < 0"
    );
    assert(test.queens == 0 && "changeQueenState modified bitboard despite invalid coordinates. (y < 0)");

    assert(changeQueenState(&test, 7, 7) && "changeQueenState should accept valid coordinates.");
    assert(test.queens == expected.queens && "changeQueenState should have modified bitboard with valid coordinates.");

    assert(changeQueenState(&test, 7, 7) && "changeQueenState should accept valid coordinates.");
    assert((test.queens == 0) && "changeQueenState should have removed the queen at specified coordinates.");

    printf("Passed.\n");
}

void testCountQueens(){
    printf("Running board.h tests...\n");
    int expected = 6;
    board test = {0x8000020001080082};
    assert(countQueens(test) == expected && "The number of queens does not match.");
    printf("Passed.\n");
}

void allBoardTests(){
    testNewBoard();
    testCoordinatesToQueen();
    testChangeQueenState();
    testCountQueens();
    printf("All board.h tests passed.\n");
}

#endif