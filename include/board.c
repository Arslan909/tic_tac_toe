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

void make_move(struct Board *board, int row, int col) {
  board->board[row][col] = board->turn;
}
void turn_change(struct Board *board) {
  board->turn = (board->turn == 'X') ? 'O' : 'X';
}
int check_valid_move(char board[3][3], int row, int col) {
  return (board[row][col] == 'X' || board[row][col] == 'O') ? 0 : 1;
}

int check_draw(struct Board *board) // 0: no draw, 1: draw
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board->board[row][col] != 'X' && board->board[row][col] != 'O') {
        return 0;
      }
    }
  }
  return 1;
}

int check_win(struct Board *board) // 0: no winner, 1: player wins
{
  // Check rows
  for (int row = 0; row < 3; row++) {
    if (board->board[row][0] == board->turn &&
        board->board[row][1] == board->turn &&
        board->board[row][2] == board->turn) {
      return board->turn;
    }
  }

  // Check columns
  for (int col = 0; col < 3; col++) {
    if (board->board[0][col] == board->turn &&
        board->board[1][col] == board->turn &&
        board->board[2][col] == board->turn) {
      return board->turn;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->turn && board->board[1][1] == board->turn &&
      board->board[2][2] == board->turn) {
    return board->turn;
  }
  if (board->board[0][2] == board->turn && board->board[1][1] == board->turn &&
      board->board[2][0] == board->turn) {
    return board->turn;
  }
  return 0;
}