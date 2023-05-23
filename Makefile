CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
OBJS = builtins.o execute.o main.o prompt.o read_line.o tokenize.o
TARGET = hsh

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
