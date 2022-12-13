#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct
{
	int j;
	int m ;
	int a ;
}datel ;


typedef struct
{
    int idListe ;
    int idTete;
    char idM1[30];
    char idM2[30];
    char idM3[20];
    datel d_debut;
    datel d_fin ;
    int nbrVote ;	
}Lelectoral;



void ajouterliste(Lelectoral l);
void supprimerliste(int id);
void modifier_listeE(Lelectoral el);
void afficher_listeE(GtkWidget *liste,char *fname);

int rechercher_listeE(int id);
Lelectoral recherche_listeE(int id);
