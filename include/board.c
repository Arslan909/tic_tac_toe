#include <stdio.h>
#include"board.h"




void init_board(struct Board *board)
{
    char k = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board->board[i][j] = k++;
        }
    }
}

void print_board(struct Board *board)
{
    printf("\n");
    printf("    ");
    for (int col = 0; col < 3; col++)
    {
        printf("%d ", col);
    }
    printf("\n");
    printf("    ");
    for (int col = 0; col < 3; col++)
    {
        printf("--");
    }
    printf("\n");
    for (int row = 0; row < 3; row++)
    {
        printf("%d | ", row);
        for (int col = 0; col < 3; col++)
        {
            printf("%c ", board->board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}
int make_move(struct Board *board, int row, int col,char character) // make move for current player
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board->board[i][j] == character)
            {
                board->board[i][j] = board->turn;

                return 1;
            }
        }
    }

    return 0;
}
void turn_change(struct Board *board)
{

    if (board->turn == 'X')
    {
        board->turn = 'O';
    }
    else
    {
        board->turn = 'X';
    }
}