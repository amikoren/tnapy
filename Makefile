CC=gcc
CFLAGS=-I.
OBJ = main.o calc.o list.o str.o notification.o

DEPS = calc.h list.h str.h notification.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

calculate: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
