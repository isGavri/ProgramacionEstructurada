.PHONY = run clean

all: main.c
	@clang -Wall --debug main.c -o main

run: all
	@./main

clean: all
	rm main
