#include "Jeu.h"

Tablette creer_tablette(){
	int i,j;
	Tablette chocolat;
	for (i = 0; i < N; ++i){
		for ( j= 0; j < M; ++j){
			chocolat.tablette[i][j]=PLEINE;
		}
	}
	
	return chocolat;
}
void manger(Tablette *tab, int x, int y){
	int i,j;
	assert(tab!=NULL);
	assert(x>=0);
	assert(x<N);
	assert(y>=0);
	assert(y<M);
	for ( i = x; i < N; ++i){
		for (j = y; j < M; ++j){
			tab->tablette[i][j]=VIDE;
		}
	}
}
int est_legal(Position pos, Coup coup){
	assert(coup.x>=0);
	assert(coup.x<N);
	assert(coup.y>=0);
	assert(coup.y<M);
	assert(pos.chocolat.tablette!=NULL);
	if(pos.chocolat.tablette[coup.x][coup.y]==PLEINE)
		return 1;
	else{
		return 0;
	}
}
int est_jeu_termine(Position pos, Joueur *joueur_gagnant){
	assert(joueur_gagnant!=NULL);
	assert(pos.chocolat.tablette!=NULL);
	if(pos.chocolat.tablette[POISON_X][POISON_Y]==PLEINE)
		return 0;
	else{
		*joueur_gagnant= pos.joueur;
		return 1;
	}
}

void jouer_coup(Position *pos, Coup coup){
	int x,y;
	assert(pos!=NULL);
	assert(coup.x>=0);
	assert(coup.x<N);
	assert(coup.y>=0);
	assert(coup.y<M);
	x=coup.x;
	y=coup.y;
	if(est_legal(*pos,coup)==PLEINE){
		manger(&(pos->chocolat),x,y);
		pos->joueur=adversaire(pos->joueur);
	}

}