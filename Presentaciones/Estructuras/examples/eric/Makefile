.PHONY = run clean

all: ejemplo.cpp
	@clang++ -Wall --debug ejemplo.cpp -o main

run: all
	@./main

clean: all
	rm main
