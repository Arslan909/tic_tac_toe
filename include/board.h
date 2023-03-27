#ifndef BOARD_H
#define BOARD_H

#define SIZE 3
#define EMPTY ' '

struct Board {
    char board[3][3];
    int turn;
};

void init_board(struct Board *board);
void print_board(struct Board *board);

#endif // BOARD_H