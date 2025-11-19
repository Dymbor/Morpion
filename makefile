morpion: object/main.o
	gcc object/main.o -o morpion

object/main.o: main.c
	gcc -Wall -c main.c -o object/main.o

clean:
	rm -f object/*.o morpion
