all: a.out

a.out: hello.c
	gcc -Wall -Werror hello.c

run: a.out
	./a.out
