CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -fsanitize=address

all: main

main: main.c cbuffer.c
	$(CC) $(CFLAGS) main.c cbuffer.c -o main

clean:
	rm -f main
