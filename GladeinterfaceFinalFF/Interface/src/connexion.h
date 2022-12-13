#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct
{
	int iduser;
	char pass [15] ;
	int role ;
	
}connexion;

connexion trouv_connexion (int id , char pass1 [] , int role1);
