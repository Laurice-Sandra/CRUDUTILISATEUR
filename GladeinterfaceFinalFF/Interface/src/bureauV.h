#ifndef __BUREAUV__H__
#define __BUREAUV__H__

typedef struct
{
	int j;
	int m;
	int a;
}dateb ;


typedef struct{
	char id[20];
	char etabl[30];
	char typeE[30];
	int nbS ;
	char Irie[30];
	char deleg[30];
	int codeP ; 
	int HoraireO;
	int HoraireF;
	int idAgentB ; 
	

}bureauV ; 


typedef struct{
	char cin[20];
	char nom[30];
	char prenom[30];
	char password[30];
	char role[30];
	char genre[30];
	int numB ; 
	dateb d;
}user ;

/* ---------------------------------------------------- */

void ajouter_bureauV(bureauV b);
void supprimer_bureauV(char id[]);
void modifier_bureauV(bureauV b);
void afficher_bureauV(GtkWidget *liste);
void afficher_nb_electeurs_bv(GtkWidget *liste);

/* ---------------------------------------------------- */

int rechercher_bureauV(char id[]);

bureauV trouverBureauV(char id[]);

#endif
