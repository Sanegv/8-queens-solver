#include "board.h"

board* newBoard(){
    board* res = malloc(sizeof(board));
    if (res == NULL)
        return NULL;
    res->queens = 0;

    return res;
}

bitboard coordinatesToQueen(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7)
        return 0;

    bitboard newQueen = 1;
    newQueen <<= x;
    newQueen <<= (y * 8);

    return newQueen;
}

bool changeQueenState(board* b, int x, int y){
    bitboard newQueen = coordinatesToQueen(x, y);
    if(!newQueen)
        return false;

    b->queens ^= newQueen;
    return true;
}

void printQueens(board b){
    printf("  A B C D E F G H\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", i+1);
        for(int j = 0; j < 8; j++){
            if(b.queens %2)
                printf("D ");
            else
                printf("# ");
            b.queens >>= 1;
        }
        printf("\n");
    }
}

int countQueens(board b){
    int count = 0;

    while(b.queens != 0){
        (b.queens & 1) ? count++ : 0;
        b.queens >>= 1;
    }

    return count;
}

void freeBoard(board* b){
    free(b);
}