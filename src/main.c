#include "../include/board.h"
#include "../include/tui.h"
#include <stdio.h>

int main() {
  struct Board board;
  struct BoardWindow board_window;
  board.board[0][0] = 'X';
  printf("%c", board.board[0][0]);
  init_board(&board);
  init_tui();
  init_board_window(&board_window);
  print_board_tui(&board, &board_window);
  end_tui();
}