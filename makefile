hw1: hw1.o hex.o base64.o
	gcc -Wall hw1.o hex.o base64.o -o hw1

hw1.o: hw1.c
	gcc -Wall -c hw1.c

hex.o: hex.c
	gcc -Wall -c hex.c

base64.o: base64.c
	gcc -Wall -c base64.c

clean: 
	rm -f *.o hw1
