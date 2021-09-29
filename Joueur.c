#include "Joueur.h"


Joueur adversaire(Joueur joueur){

	if(joueur==JOUEUR_1)
		return JOUEUR_2;
	else
		return  JOUEUR_1;
}