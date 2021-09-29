#ifndef __JOUEUR__
#define __JOUEUR__
#include <stdio.h>
#include <stdlib.h>
/*un type énuméré Joueur qui permet de modéliser les deux joueurs*/
typedef enum{
	JOUEUR_1, JOUEUR_2
}Joueur;

/*renvoie l’adversaire du joueur joueur*/
Joueur adversaire(Joueur joueur);
#endif