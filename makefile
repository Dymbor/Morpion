morpion: object/main.o object/grille.o
	gcc object/main.o object/grille.o -o morpion

object/main.o: main.c
	gcc -Wall -c main.c -o object/main.o

object/grille.o: source/grille.c headers/grille.h
	gcc -Wall -c source/grille.c -o object/grille.o


clean:
	rm -f object/*.o 
	rm -f morpion.exe