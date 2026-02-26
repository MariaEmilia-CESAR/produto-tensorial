CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = tensor

SRC = src/main.c src/matriz.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET).exe