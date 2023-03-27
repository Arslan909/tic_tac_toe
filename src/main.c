#include "../include/board.h"

int main() {
    struct Board board;
    init_board(&board);
    print_board(&board);
    return 0;
}