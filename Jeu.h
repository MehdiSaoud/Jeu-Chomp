#ifndef __JEU__
#define __JEU__
#include "Joueur.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 16
#define VIDE 0
#define PLEINE 1
#define POISON_X 0
#define POISON_Y 0
/* un type Tablette qui représente une tablette de chocolat de dimension n × m.*/
typedef struct {
	int tablette[N][M];
}Tablette;
/*un type Coup qui permet de modéliser un coup joué.*/
typedef struct{
	int x;
	int y;
}Coup;
/* un type Position qui permet de représenter une position de jeu de Chomp.*/
typedef struct {
	Tablette chocolat;
	Joueur joueur;
}Position;
/*renvoie une variable de type Tablette de dimension N × M. La tablette renvoyée
possède tous ses carrés de chocolat(des case de 1)*/
Tablette creer_tablette();
/*
 modifie la tablette tab de sorte à manger le carré de chocolat en position (x, y) ainsi
que tous ceux qui sont en dessous de lui et à sa droite.
*/
void manger(Tablette *tab, int x, int y);
/*renvoie 1 si le coup coup est légal dans la position pos et 0 sinon.
*/
int est_legal(Position pos, Coup coup);

/*renvoie 1 si la partie représentée par la position pos est terminée et 0 sinon*/
int est_jeu_termine(Position pos, Joueur *joueur_gagnant);

/*joue le coup coup dans la position pos et modifier le champ qui
contient le joueur dont c’est le tour de jouer.*/ 
void jouer_coup(Position *pos, Coup coup);

#endif