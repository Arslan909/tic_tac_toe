#include <stdio.h>
#include <conio.h>

struct Board
{
    char board[3][3];
    char turn;
    // char turn;
};

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
int make_move(struct Board *board, char charactor)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board->board[i][j] == charactor)
            {
                board->board[i][j] = board->turn;

                return 1;
            }
        }
    }

    return 0;
}
int turn_change(struct Board *board)
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

int check_win(struct Board *board)
{
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if (board->board[row][0] == board->turn && board->board[row][1] == board->turn && board->board[row][2] == board->turn)
        {
            return 1; // board->turn wins
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if (board->board[0][col] == board->turn && board->board[1][col] == board->turn && board->board[2][col] == board->turn)
        {
            return 1; // board->turn wins
        }
    }
    // Check diagonals
    if (board->board[0][0] == board->turn && board->board[1][1] == board->turn && board->board[2][2] == board->turn)
    {
        return 1; // board->turn wins
    }
    if (board->board[0][2] == board->turn && board->board[1][1] == board->turn && board->board[2][0] == board->turn)
    {
        return 1; // board->turn wins
    }
    return 0; // No winner
}
int check_draw(struct Board *board)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board->board[row][col] >= '1' && board->board[row][col] <= '9')
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    struct Board obj = {.turn = 'X'};
    init_board(&obj);
    print_board(&obj);
    while (1)
    {
        char temp;
        printf("board->player %c press the number ", obj.turn);
        scanf(" %c", &temp);
        if (make_move(&obj, temp) == 1)
        {
            print_board(&obj);
            if (check_win(&obj) == 1)
            {
                printf("%c  wins", obj.turn);
                break;
            }
            if (check_draw(&obj) == 1)
            {
                printf("draw ");
                break;
            }

            turn_change(&obj);
        }
        else
        {
            printf("invalid move ");
        }
    }
}