#ifndef TUI_H
#define TUI_H

#include "board.h"

#define HORIZONTAL_LENGTH 25
#define VERTICAL_LENGTH 13
#define HORIZONTAL_SPACING 8
#define VERTICAL_SPACING 4

struct BoardWindow {
  int start_x;
  int start_y;
  int max_x;
  int max_y;
};

void init_tui();
void init_board_window(struct BoardWindow *board_window);
void print_board_tui(struct Board *board, struct BoardWindow *board_window);
void get_maxyx_board_window(struct BoardWindow *board_window);
void end_tui();

#endif // TUI_H