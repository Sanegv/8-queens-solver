cmake_minimum_required(VERSION 3.27)
project(Queens_solver C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Queens_solver
        src/board.c
        src/board.h
        src/solver.c
        src/solver.h
        src/main.c)

add_executable(Queens_tester
        src/board.c
        src/board.h
        src/solver.c
        src/solver.h
        tests/board_test.h
        tests/solver_test.h
        tests/unitTests.c)