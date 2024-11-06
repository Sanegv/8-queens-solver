# 8-Queens solver

## Goal

The goal of this program is to solve the 8-queens problem. Note that it does not provide a solution for any other amount of queens.

The goal here was to use three concepts:
- bitwise operations;
- backtracking;
- Unit Testing (in C)

### Bitwise operations

Since we only use one type of chess piece (the Queen), and since a regular chessboard contains 64 tiles, the use of a bitboard was a great way to represent the state of the board while being memory efficient.

A bitboard consists of a long (or long long, depending on your architecture) in which each bit represents a tile, and whether its empty or occupied.

This forces the use of masks and shifts, two concepts that are essential to cryptography.

### Backtracking

A backtracking algorithm is a type of algorithm used to find a solution that satisfies some constraints.
To do so, we iterate over a tree of possibilities, and as soon as one possibility proves to violate a constraint, we eliminate it.

This kind of algorithm is used to solve problems like exploring a labyrinth,finding moves in chess, solving sudoku grids, etc.

### Unit Testing

While not a brand-new concept, I wanted to force myself to do this project properly, and TDD (Test Driven Development) allowed me to gain a lot of time when trying an implementation.
C unit testing is not as advanced as Java's JUnit or Go's Testing, but it is more than enough to create a working TDD environment.

## 8-Queens problem

The 8-Queens problem is a variant of the N-Queens problem, in which we must place N queens on an N*N grid, in such a way that no queen is threatened by another one.

That means that no two queens can occupy the same file, row, or diagonal.
We can see how similar this problem is to solving a sudoku grid.

The implementation for N-Queens is similar to the one I used for 8-Queens.
In fact, I'll probably just copy and paste the solve() function to a new project, but without limiting myself to using bitboards, and using 2D arrays to of size N*N.

## Files

This repository is divided in two main directories.

### [src](./src)

This folder contains all the actual code used for the [board](./src/board.h),the [solver](./src/solver.h), and a [main](./src/main.c) function that finds prints a solution in the terminal.

### [tests](./tests)

This folder holds all the unit tests for all the functions of src 
(except the one that prints the board).

- [unitTests](./tests/unitTests.c) has its own main, and calls all the tests of the other files.
- [board_test](./tests/board_test.h) and [solver_test](./tests/solver_test.h) test all the functions defined in [board](./src/board.h) and [solver](./src/solver.h), respectively.