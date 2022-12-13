#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connexion.h"
#include <gtk/gtk.h>

connexion trouv_connexion (int id , char pass1 [] , int role1 ){
 connexion c;
   int tr=0;
   FILE * f=fopen("connexion.txt", "r");
   if(f!=NULL)
   {
    while(tr==0 && fscanf(f,"%d %s %d",&c.iduser,c.pass,&c.role)!=EOF){
        {
            if(c.iduser!= id )
                 tr=0;
             else
		{
		 if (strcmp(c.pass,pass1)!=0)
                       tr=-1;
                 else
		   {	
		     
		    if(c.role!=role1)	
                          tr=-2;
                    else
                        tr=1;
		   }
		}
	   
	
        }
    }
    fclose(f);
   
  }
if(tr==0)
    c.iduser=-1;
if(tr==-1)
    strcpy(c.pass,"-1");

    return c;
}


