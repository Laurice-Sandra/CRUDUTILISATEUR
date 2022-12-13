#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <stdio.h>
typedef struct
{   
	int cin;
	char nom [15];
	char prenom[15];
	char sexe[3];
        char nbv[15];
	int age;
	int role;
        int vote;
	char adresse[20];
	char mail[20];
} utilisateur;

/*typedef struct
{
	int j;
	int m;
	int a;
}dateu ;*/


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
	

}bureau ; 


//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
float TPE(char *filename);
void TPHF(char *filename,float*tph,float*tpf);
int ajouter(char *, utilisateur );
int modifier( char *,utilisateur );
int supprimer(char *, int );
utilisateur chercher(char *, int);
void verifier(int x,char ajout[]);
void afficheruser(GtkWidget *liste);
void afficheruser_supp(GtkWidget *liste,utilisateur u);
void vider_supp(GtkWidget *liste);
void afficherelecteur(GtkWidget *liste);
void afficherobservateur(GtkWidget *liste);
void afficheragent_bv(GtkWidget *liste);
//affectation
int affect(char* filename, int cin,char nbv[]);
int Nombrebv(char* filename,char tab[100][15]); 
//tache
float agemoyen(char* filename);
float TPE(char *filename);
void TPHF(char *filename,float*tph,float*tpf);

#endif // UTILISATEUR_H_INCLUDED
