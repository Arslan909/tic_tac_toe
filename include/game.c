#include "game.h"
#include "board.h"
#include "tui.h"
#include <curses.h>
#include <ncurses.h>

void init_game(struct Game *game) {
  init_board(&game->board);
  init_tui();
  init_board_window(&game->board_window);
  print_board_tui(&game->board, &game->board_window);
}

void game_loop(struct Game *game) {
  int ch;

  while ((ch = getch()) != 'q') {
    switch (ch) {
    case '1':
      mvprintw(game->board_window.start_y + 2, game->board_window.start_x + 4,
               "1");
      break;
    case '2':
      mvprintw(game->board_window.start_y + 2, game->board_window.start_x + 12,
               "2");
      break;
    case '3':
      mvprintw(game->board_window.start_y + 2, game->board_window.start_x + 20,
               "3");
      break;
    case '4':
      mvprintw(game->board_window.start_y + 6, game->board_window.start_x + 4,
               "4");
      break;
    case '5':
      mvprintw(game->board_window.start_y + 6, game->board_window.start_x + 12,
               "5");
      break;
    case '6':
      mvprintw(game->board_window.start_y + 6, game->board_window.start_x + 20,
               "6");
      break;
    case '7':
      mvprintw(game->board_window.start_y + 10, game->board_window.start_x + 4,
               "7");
      break;
    case '8':
      mvprintw(game->board_window.start_y + 10, game->board_window.start_x + 12,
               "8");
      break;
    case '9':
      mvprintw(game->board_window.start_y + 10, game->board_window.start_x + 20,
               "9");
      break;
    case KEY_RESIZE:
      getmaxyx(stdscr, game->board_window.max_y, game->board_window.max_x);
      game->board_window.start_y =
          (game->board_window.max_y - VERTICAL_LENGTH) / 2;
      game->board_window.start_x =
          (game->board_window.max_x - HORIZONTAL_LENGTH) / 2;
      clear();
      print_board_tui(&game->board, &game->board_window);
      break;
    default:
      break;
    }
    refresh();
  }
}

void end_game() { end_tui(); }