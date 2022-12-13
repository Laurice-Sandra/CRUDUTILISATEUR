#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bureauV.h"

enum{
	EID,
	EETAB,
	ETYPE,
	ENBSALLE,
	EIRIE,
	EDELEG,
	ECODEP,
	EHORAIREO,
	EHORAIREF,
	EIDAB,	
	ECOLUMNS,
};

enum{
	EIDBV,
	ENOMBRE,
	ECOLUMNSS,
};


/*---------------------------------------------------------------------------------*/


void ajouter_bureauV(bureauV b){
    FILE *f;
    f = fopen("bureauV.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,b.nbS,b.Irie,b.deleg,b.codeP,b.HoraireO,b.HoraireF,b.idAgentB);
    }
    fclose(f);
}


void supprimer_bureauV(char id[]){
    bureauV b;
    FILE *f;
    FILE *g;
    f = fopen("bureauV.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF){
        if(strcmp(b.id,id) != 0){
            fprintf(g,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,b.nbS,b.Irie,b.deleg,b.codeP,b.HoraireO,b.HoraireF,b.idAgentB);
        }

    }
    fclose(f);
    fclose(g);
    remove("bureauV.txt");
    rename("tmp.txt","bureauV.txt");
}

/*--------------------------------------------------------------------------*/


void modifier_bureauV(bureauV bV){
 	bureauV b;
    FILE *f;
    FILE *g;
    f = fopen("bureauV.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF){
        if(strcmp(b.id,bV.id) == 0){
            fprintf(g,"%s %s %s %d %s %s %d %d %d %d\n",bV.id,bV.etabl,bV.typeE,bV.nbS,bV.Irie,bV.deleg,bV.codeP,bV.HoraireO,bV.HoraireF,bV.idAgentB);
        }
        else{
            fprintf(g,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,b.nbS,b.Irie,b.deleg,b.codeP,b.HoraireO,b.HoraireF,b.idAgentB);
        }
    }
    fclose(f);
    fclose(g);
    remove("bureauV.txt");
    rename("tmp.txt","bureauV.txt");

}


/*--------------------------------------------------------------------------*/
void afficher_bureauV(GtkWidget *liste){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	bureauV b ;


    char nbS[40];
    char codeP[20];
char horaireO[20];
char horaireF[20];
char idAB[20];

    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etablissement",renderer,"text",EETAB,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type d'Etablissement",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de salle",renderer,"text",ENBSALLE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IRIE",renderer,"text",EIRIE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Délegation",renderer,"text",EDELEG,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Code Postal",renderer,"text",ECODEP,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Horaire d'Ouverture",renderer,"text",EHORAIREO,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Horaire du Fermeture",renderer,"text",EHORAIREF,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Agent Bureau",renderer,"text",EIDAB,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


    
    	f = fopen("bureauV.txt","r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF){
			sprintf(nbS,"%d",b.nbS);
			sprintf(codeP,"%d",b.codeP);
			sprintf(horaireO,"%d",b.HoraireO);
			sprintf(horaireF,"%d",b.HoraireF);
			sprintf(idAB,"%d",b.idAgentB);

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,b.id,EETAB,b.etabl,ETYPE,b.typeE,ENBSALLE,nbS,EIRIE,b.Irie,EDELEG,b.deleg,ECODEP,codeP,EHORAIREO,horaireO,EHORAIREF,horaireF,EIDAB,idAB,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}

}
/*-----------------------------------------------------*/

int rechercher_bureauV(char id[]){

	bureauV b ;
	FILE *f;
	f = fopen("bureauV.txt","r");

	if(f!= NULL){
        	while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF)
		{
			if(strcmp(b.id,id) == 0)
				return 1;
		}
    	}
    	fclose(f);
	return 0;
}

bureauV trouverBureauV(char id[]){

	bureauV b ;
	FILE *f;
	f = fopen("bureauV.txt","r");

	if(f!= NULL){
        	while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF)
		{
			if(strcmp(b.id,id) == 0)
				return b;
		}
    	}
    	fclose(f);
	return;
}

void afficher_nb_electeurs_bv(GtkWidget *liste){
	bureauV b;
	user u;
	int id_bv[100];
	int nombre_electeurs[100];
	int index = 0 ;
	int count ;


	FILE *f,*g ;
	f = fopen("bureauV.txt","r");
	g = fopen("user.txt","r");

	if(f != NULL && g != NULL){
		while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF){
			count = 0 ; 
			while(fscanf(g,"%s %s %s %s %s %s %d %d/%d/%d\n",u.cin,u.nom,u.prenom,u.password,u.role,u.genre,&(u.numB),&(u.d.j),&(u.d.m),&(u.d.a))!=EOF){
				if(b.idAgentB == u.numB){
					count ++ ;
				}
			}
			id_bv[index] = b.idAgentB ;
			nombre_electeurs[index] = count ;
			index ++ ; 
		}
	}
	fclose(f);
	fclose(g);

	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	if(store == NULL){
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Numero bureau de vote",renderer,"text",EIDBV,NULL);
		column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Nombre d'Electeur",renderer,"text",ENOMBRE,NULL);
		column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(ECOLUMNSS,G_TYPE_STRING,G_TYPE_STRING);

	int k =0 ;
	while(k < index){
		gtk_list_store_append(store,&iter);
            	gtk_list_store_set(store,&iter,EIDBV,id_bv[k],ENOMBRE,nombre_electeurs[k],-1);
	}
	
}
