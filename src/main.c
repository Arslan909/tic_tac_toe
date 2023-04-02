#include "../include/board.h"
#include "../include/game.h"
#include "../include/tui.h"

#include <stdio.h>

int main() {
  struct Game game;

  init_board(&game.board);
  init_tui();
  init_board_window(&game.board_window);
  print_board_tui(&game.board, &game.board_window);
  game_loop(&game);
  end_tui();
}