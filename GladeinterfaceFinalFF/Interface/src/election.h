#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{
	int j;
	int m;
	int a;
}date;


typedef struct
{
	char id[20];
	char municipalite[20];
	char gov[20];
	char type[20];
	int nombreBV;
	int nbHabitants;
	date d;
}election;





void ajouter_election(election e);
void modifier_election(election e);
void supprimer_election(char id[]);
void afficher_election(GtkWidget *liste);

int rechercher_election(char id[]);

election trouver_election(char id[]);

int nb_conseillers (election e);
