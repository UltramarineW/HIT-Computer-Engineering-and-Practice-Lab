CC = gcc
objects = pack.o main.o
CFLAG = -I.

mytar : $(objects)
	$(CC) -o mytar $(objects)

main.o : main.c pack.h
	$(CC) -c main.c

pack.o : pack.c pack.h
	$(CC) -c pack.c

.PHONY : clean

clean : 
	rm $(objects) mytar
