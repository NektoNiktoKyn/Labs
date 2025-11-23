CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = run
SOURCES = main.c work_with_file.c finder.c animal_operations.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c animal.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
