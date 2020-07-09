# -*- Makefile -*-
all: main.o lcs.o lps.o lts.o utility.o 
	gcc -Wall -std=c99 main.o lcs.o lps.o lts.o utility.o -o output

main.o: main.c main.h
	gcc -Wall -std=c99 -c main.c

lcs.o: lcs.c lcs.h
	gcc -Wall -std=c99 -c lcs.c

lps.o: lps.c lps.h
	gcc -Wall -std=c99 -c lps.c

lts.o: lts.c lts.h
	gcc -Wall -std=c99 -c lts.c

utility.o: utility.c utility.h
	gcc -Wall -std=c99 -c utility.c

clean:
	rm -f *.o *.txt output
