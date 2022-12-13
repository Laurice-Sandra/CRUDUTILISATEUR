#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "election.h"
#include <gtk/gtk.h>

enum{
	EID,
	EMUNIC,
	EGOV,
	ETYPE,
	ENOMBREBV,
	ENBH,
	ECONS,
	EDATE,
	ECOLUMNS,
};



void ajouter_election(election e){
	FILE *f;
	f = fopen("election.txt","a");
        if(f!= NULL){
        	fprintf(f,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,e.nombreBV,e.nbHabitants,e.d.j,e.d.m,e.d.a);
    	}
    	fclose(f);
}

void modifier_election(election e){
	election y;
	FILE *f, *g;
	f=fopen("election.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d/%d/%d\n",y.id,y.municipalite,y.gov,y.type,&(y.nombreBV),&(y.nbHabitants),&(y.d.j),&(y.d.m),&(y.d.a))!=EOF)
		{
			if(strcmp(e.id,y.id) != 0)
				fprintf(g,"%s %s %s %s %d %d %d/%d/%d\n",y.id,y.municipalite,y.gov,y.type,y.nombreBV,y.nbHabitants,y.d.j,y.d.m,y.d.a);
			else
				fprintf(g,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,e.nombreBV,e.nbHabitants,e.d.j,e.d.m,e.d.a);
		}
	
		fclose(f);
		fclose(g);
		
		remove("election.txt");
		rename("temp.txt","election.txt");
	}
}


void supprimer_election(char id[]){

	election e;
	FILE *f, *g;
	f=fopen("election.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,&(e.nombreBV),&(e.nbHabitants),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
		{
			if(strcmp(e.id,id) != 0)
				fprintf(g,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,e.nombreBV,e.nbHabitants,e.d.j,e.d.m,e.d.a);
		}
	
		fclose(f);
		fclose(g);
		
		remove("election.txt");
		rename("temp.txt","election.txt");
	}
}


void afficher_election(GtkWidget *liste){

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    election e ;

    char nombreB[40];
    char nombreH[50];
    char date[50];
    char nbrConseillers[40];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Municipalité",renderer,"text",EMUNIC,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Governorat",renderer,"text",EGOV,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type d'élection",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre B_Votes",renderer,"text",ENOMBREBV,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre d'Habitants",renderer,"text",ENBH,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de conseillers",renderer,"text",ECONS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date ",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen("election.txt","r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,&(e.nombreBV),&(e.nbHabitants),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
			sprintf(date,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
			sprintf(nombreH,"%d",e.nbHabitants);
			sprintf(nombreB,"%d",e.nombreBV);
			sprintf(nbrConseillers,"%d",nb_conseillers(e));

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,e.id,EMUNIC,e.municipalite,EGOV,e.gov,ETYPE,e.type,ENOMBREBV,nombreB,ENBH,nombreH,ECONS,nbrConseillers,EDATE,date,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}


}

int rechercher_election(char id[]){
	election e ;
	FILE *f;
	f = fopen("election.txt","r");

	if(f!= NULL){
        	while(fscanf(f,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,&(e.nombreBV),&(e.nbHabitants),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
		{
			if(strcmp(e.id,id) == 0)
				return 1;
		}
    	}
    	fclose(f);
	return 0;
}

election trouver_election(char id[]){

	election e ;
	FILE *f;
	f = fopen("election.txt","r");

	if(f!= NULL){
        	while(fscanf(f,"%s %s %s %s %d %d %d/%d/%d\n",e.id,e.municipalite,e.gov,e.type,&(e.nombreBV),&(e.nbHabitants),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
		{
			if(strcmp(e.id,id) == 0)
				return e;
	
	       }
            
    	}

    	fclose(f);
	return e;
}

int nb_conseillers (election e)

{

	if ((e.nbHabitants)<5000)

	    return 10;

	else if (((e.nbHabitants)>5000)&&((e.nbHabitants)<10000))

	    return 12;

	else if ((e.nbHabitants>10000)&&(e.nbHabitants<25000))

	    return 16;

	else if ((e.nbHabitants>25000)&& (e.nbHabitants<50000))

	    return 22;

	else if ((e.nbHabitants>50000)&& (e.nbHabitants<100000))

	    return 30;

	else if ((e.nbHabitants>100000)&& (e.nbHabitants<500000))

	    return 40;

	else

	    return 60;



	return 0;

}

