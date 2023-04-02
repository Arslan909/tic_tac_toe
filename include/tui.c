#include "tui.h"
#include <curses.h>
#include <locale.h>
#include <ncurses.h>

// void print_board(int start_y, int start_x) {
//   mvprintw(start_y, start_x, "┏━━━━━━━┳━━━━━━━┳━━━━━━━┓");
//   mvprintw(start_y + 1, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 2, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 3, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 4, start_x, "┣━━━━━━━╋━━━━━━━╋━━━━━━━┫");
//   mvprintw(start_y + 5, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 6, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 7, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 8, start_x, "┣━━━━━━━╋━━━━━━━╋━━━━━━━┫");
//   mvprintw(start_y + 9, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 10, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 11, start_x, "┃       ┃       ┃       ┃");
//   mvprintw(start_y + 12, start_x, "┗━━━━━━━┻━━━━━━━┻━━━━━━━┛");
// }

void print_board_tui(struct Board *board, struct BoardWindow *board_window) {
  // clang-format off
  // more readable without the formatting tbh
    mvprintw(board_window->start_y, board_window->start_x, "┏━━━━━━━┳━━━━━━━┳━━━━━━━┓");
    mvprintw(board_window->start_y + 1, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 2, board_window->start_x, "┃   %c   ┃   %c   ┃   %c   ┃", board->board[0][0], board->board[0][1], board->board[0][2]);
    mvprintw(board_window->start_y + 3, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 4, board_window->start_x, "┣━━━━━━━╋━━━━━━━╋━━━━━━━┫");
    mvprintw(board_window->start_y + 5, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 6, board_window->start_x, "┃   %c   ┃   %c   ┃   %c   ┃",board->board[1][0], board->board[1][1], board->board[1][2]);
    mvprintw(board_window->start_y + 7, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 8, board_window->start_x, "┣━━━━━━━╋━━━━━━━╋━━━━━━━┫");
    mvprintw(board_window->start_y + 9, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 10, board_window->start_x, "┃   %c   ┃   %c   ┃   %c   ┃", board->board[2][0], board->board[2][1], board->board[2][2]);
    mvprintw(board_window->start_y + 11, board_window->start_x, "┃       ┃       ┃       ┃");
    mvprintw(board_window->start_y + 12, board_window->start_x, "┗━━━━━━━┻━━━━━━━┻━━━━━━━┛");
    getch();
  // clang-format on
}

void get_maxyx(struct BoardWindow *board_window) {
  getmaxyx(stdscr, board_window->max_y, board_window->max_x);
}

void init_board_window(struct BoardWindow *board_window) {
  get_maxyx(board_window);
  board_window->start_y = (board_window->max_y - VERTICAL_LENGTH) / 2;
  board_window->start_x = (board_window->max_x - HORIZONTAL_LENGTH) / 2;
}

void init_tui() {
  // Initialize ncurses
  setlocale(LC_ALL, "");
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
}

void end_tui() {
  // End ncurses
  endwin();
}
// int main() {
//   // Initialize ncurses
//   setlocale(LC_ALL, "");
//   initscr();
//   keypad(stdscr, TRUE);
//   noecho();
//   cbreak();

//   int max_y, max_x;
//   getmaxyx(stdscr, max_y, max_x);
//   int start_y = (max_y - VERTICAL_LENGTH) / 2;
//   int start_x = (max_x - HORIZONTAL_LENGTH) / 2;

//   // Draw the board
//   print_board_tui(start_y, start_x);

//   // Show instructions
//   mvprintw(start_y + VERTICAL_LENGTH + VERTICAL_SPACING, start_x,
//            "Press 1-9 to write numbers to the board. Press q to quit.");

//   // Capture user input and write numbers to the board
//   int ch;
//   while ((ch = getch()) != 113) {
//     switch (ch) {
//     case '1':
//       mvprintw(start_y + 2, start_x + 4, "1");
//       break;
//     case '2':
//       mvprintw(start_y + 2, start_x + 12, "2");
//       break;
//     case '3':
//       mvprintw(start_y + 2, start_x + 20, "3");
//       break;
//     case '4':
//       mvprintw(start_y + 6, start_x + 4, "4");
//       break;
//     case '5':
//       mvprintw(start_y + 6, start_x + 12, "5");
//       break;
//     case '6':
//       mvprintw(start_y + 6, start_x + 20, "6");
//       break;
//     case '7':
//       mvprintw(start_y + 10, start_x + 4, "7");
//       break;
//     case '8':
//       mvprintw(start_y + 10, start_x + 12, "8");
//       break;
//     case '9':
//       mvprintw(start_y + 10, start_x + 20, "9");
//       break;
//     case KEY_RESIZE:
//       getmaxyx(stdscr, max_y, max_x);
//       start_y = (max_y - VERTICAL_LENGTH) / 2;
//       start_x = (max_x - HORIZONTAL_LENGTH) / 2;
//       break;
//     default:
//       break;
//     }
//     refresh();
//   }

//   // End ncurses mode
//   endwin();

//   return 0;
// }
