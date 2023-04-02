CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -g

SRC_DIR=src
INC_DIR=include
BIN_DIR=bin

# src is a list of all the .c files in the src and include directories
SRC=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.c) # wildcard is a function that returns a list of all the files that match the argument

# executable is the name of the executable file
EXECUTABLE=tictactoe

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN_DIR)/$(EXECUTABLE)

run: $(EXECUTABLE)
	$(BIN_DIR)/$(EXECUTABLE)

clean:
	rm -rf $(BIN_DIR)

format:
	clang-format -i **/*.c **/*.h

.PHONY: all clean run format