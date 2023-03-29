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

int check_draw(struct Board *board)
{
    for (int row = 0; row < 3; row++) 
    {
        for (int col = 0; col < 3; col++)
        {
           if(board->board[row][col] >= '1' && board->board[row][col] <= '9'){
                return 0;
           }
        }
    }
    return 1;
}

int check_win(struct Board *board)
{
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if (board->board[row][0] == board->player && board->board[row][1] == board->player && board->board[row][2] == board->player)
        {
            return 1;
        }
    }


    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if (board->board[0][col] == board->player && board->board[1][col] == board->player && board->board[2][col] == board->player)
        {
            return 1;
        }


    }
    // Check diagonals
    if (board->board[0][0] == board->player && board->board[1][1] == board->player && board->board[2][2] == board->player)
    {
        return 1; 
    }
    if (board->board[0][2] == board->player && board->board[1][1] == board->player && board->board[2][0] == board->player)
    {
        return 1; 
    }
    return 0;
}