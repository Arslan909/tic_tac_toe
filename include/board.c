#include <stdio.h>
#include "board.h"

void init_board(struct Board *board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board->board[i][j] = EMPTY;
        }
    }
}

void print_board(struct Board *board)
{
    printf("\n");
    printf("    ");
    for (int col = 0; col < SIZE; col++)
    {
        printf("%d ", col);
    }
    printf("\n");
    printf("    ");
    for (int col = 0; col < SIZE; col++)
    {
        printf("--");
    }
    printf("\n");
    for (int row = 0; row < SIZE; row++)
    {
        printf("%d | ", row);
        for (int col = 0; col < SIZE; col++)
        {
            printf("%c ", board->board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}
void make_move(struct Board *board)
{
    // board->player 1="X"
    // board->player 2="O"

    if (board->turn % 2 == 0)
    {
        board->player = 'X';
    }
    else
    {
        board->player = 'O';
    }
    printf("board->player %c press the number ", board->player);
    int temp;
    scanf(" %d", &temp);

    int row1 = (temp - 1) / 3;
    int col1 = (temp - 1) % 3;

    if (board->board[row1][col1] != 'X' && board->board[row1][col1] != 'O')
    {
        board->board[row1][col1] = board->player;
        board->turn++;
    }
    else

        printf("INVALID MOVE");
}
