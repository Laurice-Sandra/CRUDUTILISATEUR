#include <stdlib.h>
#include <stdbool.h>
#include "lelectorale.h"
#include "callbacks.h"
#include <gtk/gtk.h>



enum{
	EID,
	ETETE,
	EMEM1,
	EMEM2,
	EMEM3,
	EDATED,
	EDATEF,
	ENBVOTE,
	ECOLUMNS,
};


/* ---------------------------------------------------------------------------------------------------- */
void ajouterliste(Lelectoral l){
	FILE *f;
	f = fopen("listeE.txt","a");
        if(f!= NULL){
        	fprintf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",l.idListe,l.idTete,l.idM1,l.idM2,l.idM3,l.d_debut.j,l.d_debut.m,l.d_debut.a,l.d_fin.j,l.d_fin.m,l.d_fin.a,l.nbrVote);
    	}
    	fclose(f);
}

/* ---------------------------------------------------------------------------------------------------- */
void supprimerliste(int id){
	Lelectoral l;
	FILE *f, *g;
	f=fopen("listeE.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",&(l.idListe),&(l.idTete),l.idM1,l.idM2,l.idM3,&(l.d_debut.j),&(l.d_debut.m),&(l.d_debut.a),&(l.d_fin.j),&(l.d_fin.m),&(l.d_fin.a),&(l.nbrVote))!=EOF)
		{
			if(l.idListe != id)
				fprintf(g,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",l.idListe,l.idTete,l.idM1,l.idM2,l.idM3,l.d_debut.j,l.d_debut.m,l.d_debut.a,l.d_fin.j,l.d_fin.m,l.d_fin.a,l.nbrVote);
		}
	
		fclose(f);
		fclose(g);
		
		remove("listeE.txt");
		rename("temp.txt","listeE.txt");
	}
}

/* ---------------------------------------------------------------------------------------------------- */


void modifier_listeE(Lelectoral el){

	Lelectoral l;
	FILE *f, *g;
	f=fopen("listeE.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",&(l.idListe),&(l.idTete),l.idM1,l.idM2,l.idM3,&(l.d_debut.j),&(l.d_debut.m),&(l.d_debut.a),&(l.d_fin.j),&(l.d_fin.m),&(l.d_fin.a),&(l.nbrVote))!=EOF)
		{
			if(l.idListe != el.idListe)
				fprintf(g,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",l.idListe,l.idTete,l.idM1,l.idM2,l.idM3,l.d_debut.j,l.d_debut.m,l.d_debut.a,l.d_fin.j,l.d_fin.m,l.d_fin.a,l.nbrVote);

			else
				fprintf(g,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",el.idListe,el.idTete,el.idM1,el.idM2,el.idM3,el.d_debut.j,el.d_debut.m,el.d_debut.a,el.d_fin.j,el.d_fin.m,el.d_fin.a,el.nbrVote);
		}
	
		fclose(f);
		fclose(g);
		
		remove("listeE.txt");
		rename("temp.txt","listeE.txt");
	}		
}

/* ---------------------------------------------------------------------------------------------------- */
void afficher_listeE(GtkWidget *liste,char *fname){

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    Lelectoral l ; 

    char idListe[40];
    char idTete[50];
    char dateD[50];
    char dateF[40];
char nbVote[30];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Liste",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID tête Liste",renderer,"text",ETETE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Membre 1",renderer,"text",EMEM1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Membre 2",renderer,"text",EMEM2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Membre 3",renderer,"text",EMEM3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date debut",renderer,"text",EDATED,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date Fin",renderer,"text",EDATEF,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de Vote",renderer,"text",ENBVOTE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",&(l.idListe),&(l.idTete),l.idM1,l.idM2,l.idM3,&(l.d_debut.j),&(l.d_debut.m),&(l.d_debut.a),&(l.d_fin.j),&(l.d_fin.m),&(l.d_fin.a),&(l.nbrVote))!=EOF){
			
			sprintf(idListe,"%d",l.idListe);
			sprintf(idTete,"%d",l.idTete);			
			sprintf(dateD,"%d/%d/%d",l.d_debut.j,l.d_debut.m,l.d_debut.a);
			sprintf(dateF,"%d/%d/%d",l.d_fin.j,l.d_fin.m,l.d_fin.a);
			
			sprintf(nbVote,"%d",l.nbrVote);


			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,idListe,ETETE,idTete,EMEM1,l.idM1,EMEM2,l.idM2,EMEM3,l.idM3,EDATED,dateD,EDATEF,dateF,ENBVOTE,nbVote,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}


}

/* -------------------------------------------------------------------------------------------------------- */

int rechercher_listeE(int id){
    Lelectoral l ; 
    FILE *f;
    f = fopen("listeE.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",&(l.idListe),&(l.idTete),l.idM1,l.idM2,l.idM3,&(l.d_debut.j),&(l.d_debut.m),&(l.d_debut.a),&(l.d_fin.j),&(l.d_fin.m),&(l.d_fin.a),&(l.nbrVote))!=EOF){
        	if(l.idListe == id){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
    

}

/* ----------------------------------------------------------------------------------------- */

Lelectoral recherche_listeE(int id){
    Lelectoral l ; 
    FILE *f;
    f = fopen("listeE.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%d %d %s %s %s %d/%d/%d %d/%d/%d %d\n",&(l.idListe),&(l.idTete),l.idM1,l.idM2,l.idM3,&(l.d_debut.j),&(l.d_debut.m),&(l.d_debut.a),&(l.d_fin.j),&(l.d_fin.m),&(l.d_fin.a),&(l.nbrVote))!=EOF){
        	if(l.idListe == id){
       		     return l;
        	}
    	}
}
    fclose(f);
    return l;
}

