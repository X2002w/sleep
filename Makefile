# sleep project Top Makefile
author = liyan
CC = gcc
LD = C:/Strawberry/c/i686-w64-mingw32/bin/ld.exe

CFLAGS = -std=c99 -ffreestanding -fno-builtin -Os -Wextra
LDFLAGS = -nostdlib -T link.ld --subsystem console
LIBDIRS = -LC:/Strawberry/c/i686-w64-mingw32/lib
LIBS = -lkernel32 

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = sleep.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) link.ld
	$(LD) $(LDFLAGS) $(LIBDIRS) -o $@ $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(TARGET)
