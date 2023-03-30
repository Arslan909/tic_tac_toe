#include "board.h"
#include <stdio.h>

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
  for (int col = 0; col < 3; col++) {
    printf("%d ", col);
  }
  printf("\n");
  printf("    ");
  for (int col = 0; col < 3; col++) {
    printf("--");
  }
  printf("\n");
  for (int row = 0; row < 3; row++) {
    printf("%d | ", row);
    for (int col = 0; col < 3; col++) {
      printf("%c ", board->board[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
void make_move(struct Board *board, int row, int col) {
  board->board[row][col] = board->turn;
}
void turn_change(struct Board *board) {
  board->turn = (board->turn == 'X') ? 'O' : 'X';
}
int check_valid_move(char board[3][3], int row, int col) {
  return (board[row][col] == 'X' || board[row][col] == 'O') ? 0 : 1;
}
