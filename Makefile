# sleep project Top Makefile
author=liyan
CC = gcc
CFLAGS = -std=c99 -nostdlib 
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = sleep

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(TARGET)
