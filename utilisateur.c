#include "utilisateur.h"
#include<stdio.h>
int ajouter(char filename [],utilisateur u )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %c %d %d %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.tel,u.mail);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier( char * filename,int id, utilisateur nv)
{
utilisateur u;
int tr=0;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nv.txt", "w");
    if(f==NULL || f2==NULL)
      return 0;
    else
        {
          while(fscanf(f,"%d %s %s %c %d %d %s %d %s\n",&u.cin,u.nom,u.prenom,&u.sexe,&u.age,&u.role,u.adresse,&u.tel,u.mail)!=EOF)
           {
             if(u.cin!=id)
                fprintf(f2,"%d %s %s %c %d %d %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.tel,u.mail);
         
             else{

                fprintf(f2,"%d %s %s %c %d %d %s %d %s\n",nv.cin,nv.nom,nv.prenom,nv.sexe,nv.age,nv.role,nv.adresse,nv.tel,nv.mail);
                tr=1;
                }
  }
        fclose(f);
        fclose(f2);
    remove(filename);
    rename("nv.txt", filename);
        return tr;
    }
  
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
     while(fscanf(f,"%d %s %s %c %d %d %s %d %s\n",&u.cin,u.nom,u.prenom,&u.sexe,&u.age,&u.role,u.adresse,&u.tel,u.mail)!=EOF)
     {
       if(u.cin!=id)
        fprintf(f2,"%d %s %s %c %d %d %s %d %s\n",u.cin,u.nom,u.prenom,u.sexe,u.age,u.role,u.adresse,u.tel,u.mail);
       else tr=1;
      }
        
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nv.txt", filename);
        return tr;
    }

}

utilisateur chercher(char * filename, int id)
{
   utilisateur u;
   int tr=0;
   FILE * f=fopen(filename, "r");
   if(f!=NULL)
   {
    while(tr==0 && fscanf(f,"%d %s %s %c %d %d %s %d %s\n",&u.cin,u.nom,u.prenom,&u.sexe,&u.age,&u.role,u.adresse,&u.tel,u.mail)!=EOF)
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

