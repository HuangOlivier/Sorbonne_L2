all: main

main : main.o biblioLC.o entreeSortieLC.o biblioH.o
	gcc -o main main.o biblioLC.o entreeSortieLC.o biblioH.o

main.o: main.c biblioLC.h entreeSortieLC.h biblioH.h
	gcc -c main.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h biblioH.h
	gcc -c entreeSortieLC.c
	
biblioLC.o : biblioLC.c biblioLC.h
	gcc -c biblioLC.c

biblioH.o : biblioH.c biblioH.h 
	gcc -c biblioH.c

clean:
	rm -f *.o main			
