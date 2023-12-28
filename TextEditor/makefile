# Compiler to use
CC=gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Name of the executable
TARGET = text_E

# Default target
all: $(TARGET)

# Rule for building the target
$(TARGET): text_E.o
	$(CC) $(CFLAGS) text_E.o -o $(TARGET)

# Rule for compiling source files
text_E.o: text_E.c
	$(CC) $(CFLAGS) -c text_E.c

# Rule for cleaning up
clean:
	rm -f *.o $(TARGET)
