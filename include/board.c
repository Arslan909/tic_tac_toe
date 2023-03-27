#include<stdio.h>
#include "board.h"

void init_board(struct Board *board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board->board[i][j] = EMPTY;
        }
    }
}


void print_board(struct Board *board) {
    printf("\n");
    printf("    ");
    for (int col = 0; col < SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    printf("    ");
    for (int col = 0; col < SIZE; col++) {
        printf("--");
    }
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        printf("%d | ", row);
        for (int col = 0; col < SIZE; col++) {
            printf("%c ", board->board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}