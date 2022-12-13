#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "utilisateur.h"

enum
{
        ECIN,
	ENOM,
	EPRENOM,
	ESEXE,
	EAGE,
	EROLE,
	EADRESSE,
        ENBV,
        EVOTE,
	EMAIL,
        COLUMNS
};


int ajouter(char filename [],utilisateur u )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
     fprintf(f,"%d %s %s %s %d %d %s %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.nbv,u.vote,u.mail);
        fclose(f);
        return 1;
    }
    else return 0;
}

void verifier(int x,char ajout[])
{
    
 
    if(x==1)
       strcpy(ajout,"Ajout avec succés");
    else 
    strcpy(ajout,"la cin est déja existante!");
        
}


int modifier( char * filename,utilisateur nv)
{
utilisateur u;
int tr=0;
    FILE * f=NULL;
     FILE * f2=NULL;
    
   f = fopen(filename, "r");
    
    if(f!=NULL)
    {

            while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
        {
      
             if(u.cin!=nv.cin)
             {  
                
             	f2 =fopen("nv.txt", "a");
                if(f2 !=NULL)
                {
                fprintf(f2,"%d %s %s %s %d %d %s %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.nbv,u.vote,u.mail);
                fclose(f2);
                }
             }
             else
	     {
		tr=1;
                f2 =fopen("nv.txt", "a");
                if(f2 !=NULL)
                {
             		fprintf(f2,"%d %s %s %s %d %d %s %s %d %s\n",nv.cin,nv.nom,nv.prenom,nv.sexe,nv.age,nv.role,nv.adresse,nv.nbv,nv.vote,nv.mail);
                }
                fclose(f2); 	
           }
       }
        fclose(f);
        remove(filename);
        rename("nv.txt", filename);
  }
        return tr;
}

int supprimer(char * filename,int id)
{
utilisateur u;
int tr=0;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nv.txt", "w");
    if(f==NULL || f2==NULL)
      return 0;
    else
    {
     while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
     {
     
       if(u.cin!=id)
        fprintf(f2,"%d %s %s %s %d %d %s %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.nbv,u.vote,u.mail);
       else tr=1;
      }
        
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nv.txt", filename);
        
    }
     return tr;
}

utilisateur chercher(char * filename, int id)
{
   utilisateur u;
   int tr=0;
   FILE * f=fopen(filename, "r");
   if(f!=NULL)
   {
    while(tr==0 && fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
        {
           if(u.cin== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.cin=-1;
    return u;

}


void afficheruser(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  utilisateur u;
  
   char cin[15];
   char role[10];
   char age[10];
   char vote[5];

    FILE *f;
   store=NULL;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
   
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
   }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f = fopen("utilisateur.txt", "r");
  if(f==NULL)
    {
        return;
    }
  else 
   {
     //f = fopen("utilisateur.txt", "a+");
      while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
      {
               sprintf(cin,"%d",u.cin);
	       sprintf(age,"%d",u.age);
	       sprintf(role,"%d",u.role);
	       sprintf(vote,"%d",u.vote);

             gtk_list_store_append(store,&iter); 
  gtk_list_store_set(store,&iter,ECIN,cin,ENOM,u.nom,EPRENOM,u.prenom,ESEXE,u.sexe,EAGE,age,EROLE,role,EADRESSE,u.adresse,ENBV,u.nbv,EVOTE,vote,EMAIL,u.mail,-1);

      }
      
      gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
       g_object_unref(store);
        fclose(f); 	
    }
  
}


void afficheruser_supp(GtkWidget *liste,utilisateur w)
{
 GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  utilisateur u;
  
   char cin[15];
   char role[10];
   char age[10];
   char vote[5];
   store=NULL;
   
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f = fopen("utilisateur.txt", "r");
  if(f==NULL)
    {
        return;
    }
  else 
   {
     f = fopen("utilisateur.txt", "a+");
      while(fscanf(f,"%d %s %s %s %d %d %s  %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
      {
       if(u.cin==w.cin)
        {
	       
	       sprintf(cin,"%d",u.cin);
	       sprintf(age,"%d",u.age);
	       sprintf(role,"%d",u.role);
                sprintf(vote,"%d",u.vote);

	       gtk_list_store_append(store,&iter); 
  gtk_list_store_set(store,&iter,ECIN,cin,ENOM,u.nom,EPRENOM,u.prenom,ESEXE,u.sexe,EAGE,age,EROLE,role,EADRESSE,u.adresse,ENBV,u.nbv,EVOTE,vote,EMAIL,u.mail,-1);
      }
      
     }
                gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    }
  
}


void vider_supp(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 
   store=NULL;
   
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

 } store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING); 
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		//g_object_unref(store);
        	
    
  
}

void afficherelecteur(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  utilisateur u;
  
   char cin[8];
   char role[5];
   char age[5];
   char vote[5];
   store=NULL;
   
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f = fopen("utilisateur.txt", "r");
  if(f==NULL)
    {
        return;
    }
  else 
   {
     f = fopen("utilisateur.txt", "a+");
      while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
      {
       if(u.role==1)
        {
	       
	       sprintf(cin,"%d",u.cin);
	       sprintf(age,"%d",u.age);
	       sprintf(role,"%d",u.role);
	       sprintf(vote,"%d",u.vote);

	       gtk_list_store_append(store,&iter); 
  gtk_list_store_set(store,&iter,ECIN,cin,ENOM,u.nom,EPRENOM,u.prenom,ESEXE,u.sexe,EAGE,age,EROLE,role,EADRESSE,u.adresse,ENBV,u.nbv,EVOTE,vote,EMAIL,u.mail,-1);
        }
      
     }
                gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    }
}


void afficherobservateur(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  utilisateur u;
  
   char cin[8];
   char role[5];
   char age[5];
   char vote[5];
   store=NULL;
   
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f = fopen("utilisateur.txt", "r");
  if(f==NULL)
    {
        return;
    }
  else 
   {
     f = fopen("utilisateur.txt", "a+");
      while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
      {
       if(u.role==2)
        {
	       
	       sprintf(cin,"%d",u.cin);
	       sprintf(age,"%d",u.age);
	       sprintf(role,"%d",u.role);
	       sprintf(vote,"%d",u.vote);

	       gtk_list_store_append(store,&iter); 
  gtk_list_store_set(store,&iter,ECIN,cin,ENOM,u.nom,EPRENOM,u.prenom,ESEXE,u.sexe,EAGE,age,EROLE,role,EADRESSE,u.adresse,ENBV,u.nbv,EVOTE,vote,EMAIL,u.mail,-1);
        }
      
     }
                gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    }
}


void afficheragent_bv(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  utilisateur u;
  
   char cin[8];
   char role[5];
   char age[5];
   char vote[5];
   store=NULL;
   
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  
   if (store==NULL)
   {
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "cin",renderer,"text",ECIN,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "nom",renderer,"text",ENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "prenom",renderer,"text",EPRENOM,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "sexe",renderer,"text",ESEXE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "age",renderer,"text",EAGE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "role",renderer,"text",EROLE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "adresse",renderer,"text",EADRESSE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "id bv",renderer,"text",ENBV,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "vote",renderer,"text",EVOTE,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

     renderer =gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes( "mail",renderer,"text",EMAIL,NULL); 		     	
     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f = fopen("utilisateur.txt", "r");
  if(f==NULL)
    {
        return;
    }
  else 
   {
     f = fopen("utilisateur.txt", "a+");
      while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
      {
       if(u.role==3)
        {
	       
	       sprintf(cin,"%d",u.cin);
	       sprintf(age,"%d",u.age);
	       sprintf(role,"%d",u.role);
	       sprintf(vote,"%d",u.vote);

	       gtk_list_store_append(store,&iter); 
  gtk_list_store_set(store,&iter,ECIN,cin,ENOM,u.nom,EPRENOM,u.prenom,ESEXE,u.sexe,EAGE,age,EROLE,role,EADRESSE,u.adresse,ENBV,u.nbv,EVOTE,vote,EMAIL,u.mail,-1);
        }
      
     }
                gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    }
}

int Nombrebv(char* filename,char tab[100][15])
{
int n=0;
 bureau b;
    FILE *f;
    
    f = fopen(filename,"r");
    if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %d %s %s %d %d %d %d\n",b.id,b.etabl,b.typeE,&(b.nbS),b.Irie,b.deleg,&(b.codeP),&(b.HoraireO),&(b.HoraireF),&(b.idAgentB)) != EOF)
  {
    strcpy(tab[n],b.id);
     n++;
     
  }
   
 }
 fclose(f);
 return n;
}

int affect(char* filename, int cin,char nbv[])
{
utilisateur u;
   int tr=0,x=0;
   FILE * f=fopen(filename, "r");
   if(f!=NULL)
   {
    while(tr==0 && fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
        {
           if(u.cin== cin)
             {
               if(u.role==1 || u.role==2)
                  {
                    strcpy(u.nbv,nbv);
                    x=modifier( "utilisateur.txt",u);
                    tr=1;
                  }
                
               }
                
        }
    }
    
    fclose(f);
    return tr;
}

//tache
float agemoyen(char* filename)
{

utilisateur u;
float t=1,e=0;
int age=0;

 FILE * f=fopen(filename, "r");
    if(f==NULL)
      return 0;
    else
    {
    
     while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
     {
       
       
       if(u.role==1)
         { 
          
         if(u.vote==1 ) 
           {
             
             e = e+1;
            age=age + u.age;
            }
           
          
         }
          
      }
        
        fclose(f);
    }
   if(e!=0)
     {
      t=(age/e);
      return t;
      }
      
   else return -1;
     
}


float TPE(char *filename)
{
utilisateur u;
float t, e=0,v=0;
 FILE * f=fopen(filename, "r");
    if(f==NULL)
      return 0;
    else
    {
      while(fscanf(f,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
     {
       

       if(u.role==1)
         { 
         e=e+1;
         if(u.vote==1 )
           v=v+1;
         }
          
      }
        
        fclose(f);
    }
   if(e!=0)
     {
      t=(v/e)*100;
      return t;
      }
      
   else return -1;
}
void TPHF(char *filename,float*tph,float*tpf)
{
 float f=0,h=0,vf=0,vh=0;
 utilisateur u;
  
 FILE * f1=fopen(filename, "r");
    if(f1==NULL)
      return;
    else
      {
         while(fscanf(f1,"%d %s %s %s %d %d %s %s %d %s\n",&u.cin,u.nom,u.prenom,u.sexe,&u.age,&u.role,u.adresse,u.nbv,&u.vote,u.mail)!=EOF)
     {
       if(u.role==1)
         { 
           if(strcmp(u.sexe,"F"))
             {
               f=f+1;
               if(u.vote==1)
                vf=vf+1;
               
              }
           else 
               {
                 h=h+1;
                if(u.vote==1)
                vh=vh+1;
              
              }
           
           
        }
     
     
     }
     fclose(f1);
    if(h!=0)
     *tph=(vh/h)*100;
    else
     *tph=-1;
    if(f!=0)
     *tpf=(vf/f)*100;
     else
     *tpf=-1;
   }

}




