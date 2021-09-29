#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__
#include "Jeu.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#define TAILLE_CASE_X 3
#define TAILLE_CASE_Y 6
#define DELAIS 500000
/*affiche sur la fenêtre standard la position pos.*/
void afficher_position(Position pos);
/*initialisation de ncurses*/
void initialisation_ncurses();

/*dessin un barre de chocolat de TAILLE_CASE à la position (x,y)*/
void dessine_choco(int x,int y);
/*efface la part du chocolat qui a été mangé*/
void efface_choco(int x,int y);

/*attend un clic de l’utilisateur sur la tablette de chocolat dans la fenêtre graphique
et calcule et renvoie le coup spécifié par l’utilisateur*/
Coup lire_coup(Position pos);
/*afficher le nom du gagnant*/
void gagnant(int tab[]);
/*renvoie le nombre de partie a jouer*/
int nb_partie_jouer();

void dessiner_case(int x, int y);
#endif