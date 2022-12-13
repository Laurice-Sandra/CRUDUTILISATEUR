#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
#include<gtk/gtk.h>
#include "observateur.h"
typedef struct
{
	int j;
	int m;
	int a;
} dateO;

typedef struct
{
	char nom[50];
	char prenom[50];
	char ville[20];
	char nationalite[20];
	char genre[20];
	char cin[20];
	dateO d;
} observateur;
void ajouter_obs( observateur o);

void afficher_obs(GtkWidget *pListView);
void modifier_obs(observateur o1);
void supprimer_observateur(char cin[30]);
void chercher_obs(char idchercher[20],GtkWidget *liste);
int obstunisien(char * name1);
int calcul_observateur(char * name1);

#endif // observateur_H_INCLUDED

