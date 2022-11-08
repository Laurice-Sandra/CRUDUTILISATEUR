#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <stdio.h>
typedef struct
{
    char nom [50];
    char prenom[50];
    char sexe;
    char mail[50];
    char adresse[50];
    int cin,role,age,tel;
} utilisateur;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter(char *, utilisateur );
int modifier( char *, int, utilisateur );
int supprimer(char *, int );
utilisateur chercher(char *, int);

#endif // UTILISATEUR_H_INCLUDED
