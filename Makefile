all: $(patsubst %.c, %, $(wildcard *.c))

run: run.c
	gcc -Wall -g run.c -o run

%: %.c
	gcc -Wall -g $< -o $@

clean:
	rm -rf run aoc*.1 aoc*.2 *.dSYM
