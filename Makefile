CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -g

SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

# src is a list of all the .c files in the src and include directories
SRC=$(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.c) # wildcard is a function that returns a list of all the files that match the argument

# make a list of all the .o files in the obj directory from the .c files in the src and include directories
OBJ=$(patsubst %.c, %.o, $(SRC)) # patsubst is a function that takes a list of files and replaces the first argument with the second argument

# executable is the name of the executable file
EXECUTABLE=tictactoe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(EXECUTABLE) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	$(BIN_DIR)/$(EXECUTABLE)

clean:
	rm $(OBJ)
	rm -rf $(BIN_DIR)

format:
	clang-format -i **/*.c **/*.h

.PHONY: all clean run format