all:main.c
	gcc -o main main.c

run: make
	./make