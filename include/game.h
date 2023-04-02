#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tui.h"

struct Game {
  struct Board board;
  struct BoardWindow board_window;
};

void init_game(struct Game *game);
void game_loop(struct Game *game);
void end_game();

#endif // GAME_H