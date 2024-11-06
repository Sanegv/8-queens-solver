#ifndef QUEENS_SOLVER_SOLVER_TEST_H
#define QUEENS_SOLVER_SOLVER_TEST_H

#include <assert.h>
#include "src/solver.h"

void testSolve(){
    printf("Running solve() tests... ");

    board test = {0};
    assert(solve(&test, 0) && "solve() should find a solution");
    assert(countQueens(test) == 8 && "Solution should have eight queens exactly.");
    assert(checkPlacement(&test) && "Solution should be valid.");

    test.queens = 0x3;
    assert(!solve(&test, 0) && "solve() should not find an impossible solution");
    assert((test.queens == 0x3) && "solve() should not alter the board if it does not find a solution.");

    printf("Passed.\n");
}

void testCheckPlacement(){
    printf("Running checkPlacement() tests... ");

    board test = {0};
    assert(checkPlacement(&test) && "Empty board should be valid.");
    test.queens = 0x800000000;
    assert(checkPlacement(&test) && "Board with one queen should be valid.");
    test.queens = 0x800100000;
    assert(checkPlacement(&test) && "Board with two separated queens should be valid.");
    test.queens = 0x22000000;
    assert(!checkPlacement(&test) && "Board with two queens on the same rank should not be valid.");
    test.queens = 0x2000002;
    assert(!checkPlacement(&test) && "Board with two queens on the same file should not be valid.");
    test.queens = 0x2000800000;
    assert(!checkPlacement(&test) && "Board with two queens on the same diagonal should not be valid.");
    test.queens = 0x20100000000;
    assert(!checkPlacement(&test) && "Board with two queens on the same anti-diagonal should not be valid.");
    test.queens = 0x410800801400220;
    assert(checkPlacement(&test) && "Puzzle solution should be valid.");

    printf("Passed.\n");
}

void testCheckDiagonals(){
    printf("Running checkDiagonals() tests... ");

    board test = {0};
    assert(checkDiagonals(&test) && "Empty board should be valid.");
    test.queens = 0x800000000;
    assert(checkDiagonals(&test) && "Board with one queen should be valid.");
    test.queens = 0x800100000;
    assert(checkDiagonals(&test) && "Board with two separated queens should be valid.");
    test.queens = 0x22000000;
    assert(checkDiagonals(&test) && "Board with two queens on the same rank should be valid.");
    test.queens = 0x2000002;
    assert(checkDiagonals(&test) && "Board with two queens on the same file should be valid.");
    test.queens = 0x410800801400220;
    assert(checkDiagonals(&test) && "Puzzle solution should be valid.");
    
    test.queens = 0x8002000000000;
    assert(!checkDiagonals(&test) && "Board with two queens on the same (lower) diagonal should not be valid.");
    test.queens = 0x408;
    assert(!checkDiagonals(&test) && "Board with two queens on the same (upper) diagonal should not be valid.");
    test.queens = 0x2000000002000000;
    assert(!checkDiagonals(&test) && "Board with two queens on the same (lower anti) diagonal should not be valid.");
    test.queens = 0x80000000000400;
    assert(!checkDiagonals(&test) && "Board with two queens on the same (upper anti) diagonal should not be valid.");
    test.queens = 0x4080000000000000;
    assert(!checkDiagonals(&test) && "Board with two queens on the last (lower) diagonal should not be valid.");
    test.queens = 0x102;
    assert(!checkDiagonals(&test) && "Board with two queens on the last (upper) diagonal should not be valid.");
    test.queens = 0x201000000000000;
    assert(!checkDiagonals(&test) && "Board with two queens on the last (lower anti) diagonal should not be valid.");
    test.queens = 0x8040;
    assert(!checkDiagonals(&test) && "Board with two queens on the last (upper anti) diagonal should not be valid.");

    printf("Passed.\n");
}

void testCheckFiles(){
    printf("Running checkFiles() tests... ");

    board test = {0};
    assert(checkFiles(&test) && "Empty board should be valid.");
    test.queens = 0x800000000;
    assert(checkFiles(&test) && "Board with one queen should be valid.");
    test.queens = 0x800100000;
    assert(checkFiles(&test) && "Board with two separated queens should be valid.");
    test.queens = 0x22000000;
    assert(checkFiles(&test) && "Board with two queens on the same rank should be valid.");
    test.queens = 0x410800801400220;
    assert(checkFiles(&test) && "Puzzle solution should be valid.");
    test.queens = 0x2000002;
    assert(!checkFiles(&test) && "Board with two queens on the same file should not be valid.");
    test.queens = 0x8000800000000000;
    assert(!checkFiles(&test) && "Board with two queens on the last file should not be valid.");

    printf("Passed.\n");
}

void testCheckRanks(){
    printf("Running checkRanks() tests... ");

    board test = {0};
    assert(checkRanks(&test) && "Empty board should be valid.");
    test.queens = 0x800000000;
    assert(checkRanks(&test) && "Board with one queen should be valid.");
    test.queens = 0x800100000;
    assert(checkRanks(&test) && "Board with two separated queens should be valid.");
    test.queens = 0x800080000;
    assert(checkRanks(&test) && "Board with two queens on the same file should be valid.");
    test.queens = 0x410800801400220;
    assert(checkRanks(&test) && "Puzzle solution should be valid.");
    test.queens = 0x410000;
    assert(!checkRanks(&test) && "Board with two queens on the same rank should not be valid.");
    test.queens = 0xa000000000000000;
    assert(!checkRanks(&test) && "Board with two queens on the last rank should not be valid.");

    printf("Passed.\n");
}

void testCheckEmpty(){
    printf("Running checkEmpty() tests... ");

    board test = {0x80000};
    assert(checkEmpty(&test, 0, 0) && "Empty tile should return true.");
    assert(!checkEmpty(&test, 3, 2) && "Occupied tile should return false.");
    assert(!checkEmpty(&test, -1, 2) && "x < 0 should return false.");
    assert(!checkEmpty(&test, 1, -1) && "y < 0 should return false.");
    assert(!checkEmpty(&test, 8, 2) && "x > 7 should return false.");
    assert(!checkEmpty(&test, 1, 8) && "y > 7 should return false.");

    printf("Passed.\n");
}

void allSolverTests(){
    printf("Running solver.h tests...\n");

    testCheckEmpty();
    testCheckRanks();
    testCheckFiles();
    testCheckDiagonals();
    testCheckPlacement();
    testSolve();

    printf("All solver.h tests passed.\n");
}

#endif //QUEENS_SOLVER_SOLVER_TEST_H
