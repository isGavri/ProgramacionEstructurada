.PHONY = all run clean

all: main.cpp
	@clang++ -Wall -Werror --debug main.cpp -o main -lmariadbcpp

run: all main
	@./main

clean: main
	@rm main
	@rm main.s
	@echo "Binaries removed and assembly removed"
