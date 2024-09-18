CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I./libmx/inc

LIBS = ./libmx/libmx.a

SRC_DIR = src
OBJ_DIR = obj
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

TARGET = check

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
