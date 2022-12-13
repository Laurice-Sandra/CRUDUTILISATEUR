#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "observateur.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum 
{
	ENOM,
	EPRENOM,
	EVILLE,
	EGENRE,
	ENATIONALITE,
	ECIN,
	D,
	COLUMNS,
};



void ajouter_obs( observateur o)
{
    FILE *f;
f=fopen("observateur.txt", "a+");
    if(f!=NULL)
    {
	if (o.cin !="")
	{
fprintf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);
        fclose(f);
        
    }
   }
}


void afficher_obs(GtkWidget *pListView)
{

GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
GtkTreeIter pIter;


	observateur o;
	char nom[50];
	char prenom[50];
	char ville[20];
	char genre[20];
	char nationalite[20];
	char cin[20];
	dateO d;

char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;
pListStore=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(pListView)));
//pListStore=gtk_tree_view_get_model(pListView);

if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom",pCellRenderer,"text", ENOM,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom",pCellRenderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("ville",pCellRenderer,"text",EVILLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nationalite",pCellRenderer,"text",ENATIONALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("genre",pCellRenderer,"text", EGENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("cin",pCellRenderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("d",pCellRenderer,"text",D,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pListStore = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("observateur.txt","r");
if (f==NULL){return;}
else{f=fopen("observateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
	{
/*sprintf(var1,"%d",l.id_liste);
sprintf(var2,"%d",l.id_election);
sprintf(var3,"%d",l.id_electeur2);
sprintf(var4,"%d",l.id_electeur3);*/
sprintf(var5,"%d/%d/%d",o.d.j,o.d.m,o.d.a);

///

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,ENOM,o.nom,EPRENOM,o.prenom,EVILLE,o.ville,ENATIONALITE,o.nationalite,EGENRE,o.genre,ECIN,o.cin,D,var5,-1);


}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
       }
}

}


void modifier_obs(observateur o1)
{
observateur o;
int trouve=0;
FILE *f,*f1;
f=NULL;
f1=NULL;
f=fopen("observateur.txt","r");
f1=fopen("liste.txt","w+");
if(f!=NULL)
{while((fscanf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF))
{
if(strcmp(o.cin,o1.cin)==0)
{trouve=1;

fprintf(f1,"%s %s %s %s %s %s %d %d %d \n",o1.nom,o1.prenom,o1.ville,o1.nationalite,o1.genre,o1.cin,o1.d.j,o1.d.m,o1.d.a);
}
else
{fprintf(f1,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);
}
}
}

fclose(f);
fclose(f1);
remove("observateur.txt");
rename("liste.txt","observateur.txt");
}

void supprimer_observateur(char cin[30])
{
    int tr=0;
    observateur o;
    FILE *f;
    FILE *f2;
f=fopen("observateur.txt","r");
f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
        {
		
            if(strcmp(o.cin,cin)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);
        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouv.txt","observateur.txt");
}
void chercher_obs(char idchercher[20],GtkWidget *liste)

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

        observateur o;
	char nom[20];
        char prenom[20];
        
        dateO d;
        
        char ville[100];
        char nationalite[100];
        char var[20];
        char cin[20]; 
        char genre[20];
        
        int tr=0;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text",EVILLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite", renderer,"text",ENATIONALITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer,"text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	
	column = gtk_tree_view_column_new_with_attributes("cin", renderer,   "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("d", renderer, "text",D,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("observateur.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("observateur.txt","a+");
		while((fscanf(f,"%s %s %s %s %s %s %d %d %d \n",nom,prenom,ville,nationalite,genre,cin,&d.j,&d.m,&d.a)!=EOF)&&(tr==0))
                      {
                        sprintf(var,"%d %d %d",d.j,d.m,d.a);
                     
                        if (strcmp(cin,idchercher)==0)
                        {tr=1;
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENOM,nom, EPRENOM,prenom, EVILLE, ville, ENATIONALITE ,nationalite,EGENRE,genre, ECIN, cin,D,var, -1);
		}
                }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}

}


/*int modifier( char  obs[20], int id, observateur nouv )
{   observateur o ;
    int tr=0;
    FILE * f=fopen(obs, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,&o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
        {
            if(o.cin== id)
            {
                fprintf(f2,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);

        }
    }
    fclose(f);
    fclose(f2);
    remove(obs);
    rename("nouv.txt", obs);
    return tr;

}





int supprimer(char  obs[20], int id)
{
    int tr=0;
    observateur o;
    FILE * f=fopen(obs, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,&o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
        {
            if(o.cin== id)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,o.d.j,o.d.m,o.d.a);
        }
    }
    fclose(f);
    fclose(f2);
    remove(obs);
    rename("nouv.txt", obs);
    return tr;
}




observateur chercher(char obs[20], int id)
{
    observateur o;
    int tr;
    FILE * f=fopen(obs, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,&o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
        {
            if(o.cin== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        o.cin=-1;
    return o;

}*/

int calcul_observateur(char * name1)
{
observateur o ;
int nbr=0;


    FILE * f=fopen(name1, "r");
    if(f!=NULL)
    { while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
       
	nbr=nbr+1;
}

    fclose(f);
    return (nbr);

}


/*
  int calculer(){
     FILE *fileptr;
    int count_lines = 0;
    char chr;


    fileptr = fopen("observateur.txt", "r");
    
   
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
               

    count_lines = count_lines + 1;
    fclose(fileptr);
    return count_lines ;
    }
  */  



//int calcul_observateur(char *name1)
//{   int count=0;
//char c ;
  //  FILE * f=fopen(name1, "r");
    //if (f == NULL)
   // {
     //   printf("Could not open file ");
       // return 0;
   // }
 
    // Extract characters from file and store in character c
    //for (c = getc(f); c != EOF; c = getc(f))
      //  if (c == '\n') // Increment count if this character is newline
        //    count = count + 1;
 
    // Close the file
    //fclose(f);
   // return count;

//}*/


int obstunisien(char * name1)
{
observateur o ;
 int nbrtn=0;

//double ttn;	
    FILE * f=fopen(name1, "r");
    if(f!=NULL)
    { while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",o.nom,o.prenom,o.ville,o.nationalite,o.genre,o.cin,&o.d.j,&o.d.m,&o.d.a)!=EOF)
       if (strcmp(o.nationalite,"tunisienne")==0)

	nbrtn=nbrtn+1;
}

    fclose(f);
    //ttn=(nbrtn/nbr)*100;
    
    return nbrtn;
}

/*
void afficher_observateur (GtkWidget *liste);
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *cloumn;
GtkTreeIter iter;
GtkistStore *store;

char nom[50];
char prenom[50];
char ville[20];
char profession[20];
char nationalite[20];
char genre[20];
int cin;
store=NULL;


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_colum_new_with_attributes("nom",renderer, "nom",cin, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


*/







