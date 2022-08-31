CC = gcc
CFLAG = -Wall
OBJECTS = main.o sort.o

all : runsort randdata

randdata : randdata.o sort.o
	$(CC) $(CFLAG) -o randdata randdata.o sort.o

runsort : $(OBJECTS)
	$(CC) $(CFLAG) -o runsort $(OBJECTS)
	
main.o : main.c sort.h
	$(CC) $(CFLAG) -c main.c

sort.o : sort.c sort.h
	$(CC) $(CFLAG) -c sort.c

randdata.o : randdata.c sort.h
	$(CC) $(CFLAG) -c randdata.c
	
.PHONY : clean 

clean:
	rm $(OBJECTS) runsort randdata randdata.o
