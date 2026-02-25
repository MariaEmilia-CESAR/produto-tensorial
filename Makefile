CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = mess

all: $(TARGET)

$(TARGET): mess.c
	$(CC) $(CFLAGS) mess.c -o $(TARGET)

clean:
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)