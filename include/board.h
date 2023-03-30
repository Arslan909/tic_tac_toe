#ifndef BOARD_H
#define BOARD_H

#define SIZE 3
#define EMPTY ' '

struct Board
{
    char board[3][3];
    char turn;
};

void init_board(struct Board *board);
void print_board(struct Board *board);
int check_board(struct Board *board);                     // 0: no winner, 1: X wins, 2: O wins, 3: draw
int check_win(char board[3][3], char player);             // 0: no winner, 1: player wins
int check_draw(char board[3][3]);                         // 0: no draw, 1: draw
int check_valid_move(char board[3][3], int row, int col); // 0: invalid move, 1: valid move
void make_move(struct Board *board, int row, int col);    // make move for current player
void turn_change(struct Board *board);

#endif // BOARD_H