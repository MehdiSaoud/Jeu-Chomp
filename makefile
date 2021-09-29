CC = gcc
CFLAGS = -ansi -pedantic -Wall -lncurses
OBJ = Main.o Joueur.o Jeu.o  Graphique.o

Chomp: $(OBJ)
	$(CC) -o Chomp $(OBJ) $(CFLAGS) 

Main.o: Main.c Jeu.h Graphique.h 
	gcc -c Main.c

Jeu.o: Jeu.c Jeu.h Joueur.h
	gcc -c Jeu.c
Joueur.o: Joueur.c Joueur.h
	gcc -c Joueur.c
	

Graphique.o: Graphique.c Graphique.h
	gcc -c Graphique.c
mrproper:
	rm -f *.o

clean:
	rm -f Chomp

vacuum:
	make mrproper
	make clean