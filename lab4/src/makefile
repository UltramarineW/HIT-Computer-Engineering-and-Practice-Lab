CC = gcc
CFLAG = -Wall -g
OBJECTS = main.o utils.o sort.o fileop.o

system : $(OBJECTS)
	$(CC) $(CFLAG) -o system $(OBJECTS)

main.o : main.c utils.h sort.h fileop.h struct.h
	$(CC) $(CFLAG) -c main.c

utils.o : utils.c utils.h sort.h struct.h fileop.h
	$(CC) $(CFLAG) -c utils.c

sort.o : sort.c sort.h utils.h struct.h
	$(CC) $(CFLAG) -c sort.c

fileop.o : fileop.c fileop.h utils.h struct.h
	$(CC) $(CFLAG) -c fileop.c
	

.PHONY : clean

clean:
	rm $(OBJECTS) system
