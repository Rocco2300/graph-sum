CC = gcc
CFLAGS = -g
TARGET = a

SRC = src
OBJ = obj
INC = include

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(SRCS:$(SRC)/%.c=$(OBJ)/%.o)

.PHONY: all clean

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(CCFLAGS) -I $(INC) $< -o $@

clean:
	del /f obj\\*.o
	del /f a.exe