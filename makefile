scr: testDriver.o scrambled.o 
	gcc -o scr testDriver.o scrambled.o

testDriver.o: testDriver.c
	gcc -Wall -c testDriver.c

scrambled.o: scrambled.c
	gcc -Wall -c scrambled.c

clean:
	rm -f scr *.o