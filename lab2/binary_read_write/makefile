CC = gcc
CFLAG = -I.
objects = main.o fileop.o

file_write : $(objects) 
	$(CC) -o file_write $(objects)

main.o : main.c fileop.h
	$(CC) -c main.c

fileop.o : fileop.c fileop.h
	$(CC) -c fileop.c

.PHONY : clean
clean:
	rm file_write $(objects)
