CC =gcc
CLAG = -I. -g
object = main.o bubbleSort.o heapSort.o mergeSort.o quickSort.o selectSort.o insertSort.o Swap.o

runsort : $(object)
	$(CC) $(CFLAG) -o runsort $(object)

main.o : main.c sort.h
	$(CC) $(CFLAG) -c main.c

bubbleSort.o : bubbleSort.c sort.h
	$(CC) $(CFLAG) -c bubbleSort.c

quickSort.o : quickSort.c sort.h
	$(CC) $(CFLAG) -c quickSort.c

selectSort.o : selectSort.c sort.h
	$(CC) $(CFLAG) -c selectSort.c

heapSort.o : heapSort.c sort.h
	$(CC) $(CFLAG) -c heapSort.c

insertSort.o : insertSort.c sort.h
	$(CC) $(CFLAG) -c insertSort.c

Swap.o : Swap.c sort.h
	$(CC) $(CFLAG) -c Swap.c

mergeSort.o : mergeSort.c sort.h
	$(CC) $(CFLAG) -c mergeSort.c

	
.PHONY : clean

clean : 
	-rm $(object) runsort
