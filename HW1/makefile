all: clean compile run
clean:
	@rm -rf test
compile: main.cpp lib.cpp lib.h
	@g++ main.cpp lib.cpp lib.h -o test -lm
run: test
	@./test
