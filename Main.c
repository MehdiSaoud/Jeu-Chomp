/* Auteur : MEHDI SAOUD /NDIAYE MOUSSA
* Creation : 27-02-2020
* Modification : 2-03-2020 */
#include "Jeu.h"
#include "Graphique.h"
int main(int argc, char const *argv[]){

	int nb_parties,partie;
	int score[2];
	Coup coup;
	Position pos;
	Joueur joueur,joueur_gagnant;
	initialisation_ncurses();
	
	score[1]=score[0]=0;
	partie=1;
	mvprintw(LINES/2,COLS/2-40,"Assurez vous de mettre le terminal en mode plein écran avant la compilation merci. ");
	refresh();
	usleep(4000000);
	clear();
	nb_parties=nb_partie_jouer();
	do{

		
		joueur=JOUEUR_1;
	
		
		pos.chocolat=creer_tablette();
		pos.joueur=joueur;
 	    attron(A_UNDERLINE | A_BOLD);
		mvprintw(LINES/2- TAILLE_CASE_X,COLS/2-10,"%d %s partie",partie,(partie==1)? "ère":"ème");
		attroff(A_UNDERLINE | A_BOLD);
		refresh();
		usleep(1000000);
		clear();
				
		while(!est_jeu_termine(pos, &pos.joueur)){
			attron(A_BOLD);
   			
			mvprintw(LINES-5, 1, "Le nombres de parties restante : %d", nb_parties);
			mvprintw(10, COLS-30, "Le score actuel : ");
			attron(A_UNDERLINE);
			mvprintw(12, COLS-32,"Joueur1  %d : %d  Joueur2",score[0],score[1] );
			attroff(A_BOLD | A_UNDERLINE);
			afficher_position(pos);

			coup=lire_coup(pos);
			jouer_coup(&pos, coup);
			clear();				
		}
		if(pos.joueur==JOUEUR_1)
			score[0]++;
		else
		 	score[1]++;
		nb_parties--;
		partie++;	
	}while(nb_parties>0);

	clear();
	//while(1)
	gagnant(score);
	usleep(DELAIS);
	endwin();
	return 0;
}