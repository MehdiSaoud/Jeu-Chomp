#include "Graphique.h"

void initialisation_ncurses(){

	initscr();
	start_color();
	use_default_colors();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,NULL);
	keypad(stdscr, TRUE);
	
	curs_set(0);
	

}


void dessiner_case(int x, int y){
	init_pair(5, COLOR_YELLOW,-1);
	init_pair(2, COLOR_BLUE,-1);
	int case_x, case_y;
	int i,j;
	assert(x>=0);
	assert(y>=0);
	case_x = (x+1)*TAILLE_CASE_X ;  /*+1*/
	case_y = (y+1)*TAILLE_CASE_Y;
	attron(COLOR_PAIR(2));

	mvprintw(TAILLE_CASE_X/2+1,TAILLE_CASE_Y/2,"O");
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(5));
	for (i = x; i <= case_x; i++){
		for (j = y; j <= case_y ; j++){
			if (i==0){
				if (j==0)
		    		mvaddch(i, j, ACS_ULCORNER); /*Coin haut à gauche*/
		    	else if (j==(case_y) )
		    		mvaddch(i, j, ACS_URCORNER); /*Coin haut à droite*/
		    	else 
		    		mvaddch(i, j, ACS_S7);	/*La premiere ligne*/
			}
			else if (j == 0 || j==(case_y) ) {
				mvaddch(i, j, ACS_VLINE);

				if (j==y && (i == case_x ))
					mvaddch(i, j, ACS_LLCORNER);
				else if(j==(case_y) && (i == case_x ))
					mvaddch(i, j, ACS_LRCORNER);
			}
			else if(i == case_x )
				mvaddch(i, j, ACS_S7);
		    
		}
	}
	 attroff(COLOR_PAIR(5));
}
void afficher_position(Position pos){
	int i,j;
	attron(A_BOLD);
	mvprintw(LINES-1, 0, "Tour du %s !", (pos.joueur) ? "JOUEUR 2" : "JOUEUR 1" );
	attroff(A_BOLD);
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (pos.chocolat.tablette[i][j] == PLEINE )
				dessiner_case(i, j);
			}
	}
}
static int valide(Coup coup){
	if(coup.x>=0 && coup.x<N && coup.y>=0 && coup.y<M)
		return 1;
	return 0;
}
Coup lire_coup(Position pos){
	Coup coup;
	MEVENT ev;
	int touche;
	do{
		touche=getch();
		if(touche==KEY_MOUSE && getmouse(&ev)==OK){
		
			coup.y=(ev.x/TAILLE_CASE_Y);
			coup.x=(ev.y/(TAILLE_CASE_X));

			mvprintw(LINES-5,COLS-5,"%d,%d",coup.x,coup.y);

		}
		touche=0;
	}while(!valide(coup));
	return coup;
}

void gagnant(int tab[]){
	int i,j;
	
	init_pair(1, COLOR_GREEN,-1);
	init_pair(2, COLOR_RED,-1);
	init_pair(3, COLOR_BLUE,-1);
	init_pair(4, COLOR_WHITE,-1);
	init_pair(5, COLOR_YELLOW,-1);
	for(j=0 ; j < 1000 ; j++){
     
        for(i=0 ; i<5;i++){

            
            mvprintw(LINES/2- TAILLE_CASE_X-4,COLS/2-10,"*****************************");
            attron(COLOR_PAIR(i)); 
            mvprintw(LINES/2- TAILLE_CASE_X-3,COLS/2-10,"*****************************");
            mvprintw(LINES/2- TAILLE_CASE_X-1,COLS/2-10,"*****************************");
            if(tab[0]<tab[1])
        		mvprintw(LINES/2- TAILLE_CASE_X,COLS/2-10,"Le JOUEUR_2 a gagné %d à %d",tab[1],tab[0]);
			else if(tab[0]>tab[1])
				mvprintw(LINES/2- TAILLE_CASE_X,COLS/2-10,"Le JOUEUR_1 a gagné %d à %d",tab[0],tab[1]);
			else
				mvprintw(LINES/2- TAILLE_CASE_X,COLS/2-5,"Match NULL %d points partout",tab[0]);
            mvprintw(LINES/2- TAILLE_CASE_X+1,COLS/2-10,"*****************************");  
            mvprintw(LINES/2- TAILLE_CASE_X+3,COLS/2-10,"*****************************");
            attroff(COLOR_PAIR(i));      
            mvprintw(LINES/2- TAILLE_CASE_X+4,COLS/2-10,"*****************************");
            refresh();
            usleep(DELAIS);
        }
    }
  
}
int nb_partie_jouer(){
	int nb_partie_joueur1,nb_partie_joueur2,moyen;
	attron(A_BOLD);
	mvprintw(LINES/2,COLS/2-30,"Enter le nombre de partie pour le joueur1 puis appuyez sur Enter:\n");
    mvscanw(LINES/2,COLS/2+35,"%d", &nb_partie_joueur1);
    clear();
	mvprintw(LINES/2+1,COLS/2-30,"Enter le nombre de partie pour le joueur2 puis appuyez sur Enter:\n");
	mvscanw(LINES/2+1,COLS/2+35,"%d", &nb_partie_joueur2);
	attroff(A_BOLD);
	clear();
	moyen=(nb_partie_joueur1+nb_partie_joueur2)/2;
	return  moyen;


	

}