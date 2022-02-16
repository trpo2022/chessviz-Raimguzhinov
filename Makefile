all: chessviz.out run delete

chessviz.out: chessviz.cpp
	g++ -Wall -Werror -o chessviz.out chessviz.cpp

run: chessviz.out
	./chessviz.out

delete: chessviz.out
	rm chessviz.out
