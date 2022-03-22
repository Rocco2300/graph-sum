CC = gcc
CFLAGS = -g
TARGET = graph_sum
DOT_TARGET = output.svg

SRC = src
OBJ = obj
INC = include

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(SRCS:$(SRC)/%.c=$(OBJ)/%.o)

.PHONY: all clean vis

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(CCFLAGS) -I $(INC) $< -o $@

vis:
	dot -Tsvg output.dot > output.svg

clean:
	del /f obj\\*.o
	del /f *.exe