all: spySam2

spySam2: spySam2.o

example.o: spySam2.c
	gcc -c spySam2.c
