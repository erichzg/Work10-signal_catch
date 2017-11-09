all: catch_signal.c
	gcc -o catch_signal catch_signal.c
run: all
	./catch_signal
