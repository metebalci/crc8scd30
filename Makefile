
CC			=	gcc
CFLAGS	=	-std=c11 -Wall -Wextra -Wpedantic -Wshadow -Werror
DEPS		=	crc8scd30.h
OBJ			=	crc8scd30.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o test test.o crc8scd30.o $(CFLAGS)

test: all
	./test

clean:
	rm -f test *.o
