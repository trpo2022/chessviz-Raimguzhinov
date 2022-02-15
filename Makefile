all: chessviz.out

chessviz.out: chessviz.cpp
	g++ -Wall -Werror -o chessviz.out chessviz.cpp

run: chessviz.out
	./chessviz.out
