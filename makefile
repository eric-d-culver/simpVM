# makefile for simpVM project

# first, some global variables
WARNINGS = -Wall
CC=gcc -std=c11 
CFLAGS=-c $(WARNINGS)
LDFLAGS= 

# second, some local variables
HEADERS=list.h stack.h read.h commands.h
CLASSES=stack.c read.c

SOURCES=$(CLASSES) main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=simpVM # change to whatever the executable should be called

# finally,, some make commands
all: $(HEADERS) $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# .cpp.o:
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean cleanup new all


new:
	rm -rf *.o
	make

cleanup:
	rm -rf *.o

clean:
	rm -rf *.o $(EXECUTABLE1)
