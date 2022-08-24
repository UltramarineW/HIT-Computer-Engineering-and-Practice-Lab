CC=gcc
CFLAG=-I.
objects = main.o fileop.o

fileop: $(objects)
	$(CC) -o fileop $(objects)

main.o: main.c fileop.h
	$(CC) -c main.c
	
fileop.o: fileop.c fileop.h
	$(CC) -c fileop.c

.PHONY : clean
clean:
	-rm fileop $(objects)

