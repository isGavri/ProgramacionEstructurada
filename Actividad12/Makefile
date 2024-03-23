.PHONY = all run clean

all: main.cpp
	@clang++ --debug main.cpp -o main 

run: all main
	@./main

clean: main
	@rm main
	@echo "Cleaned"
