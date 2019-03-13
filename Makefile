
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Wshadow

test:
	gcc -o test test.c crc8scd30.c $(CFLAGS)
	./test

clean:
	rm -f test
