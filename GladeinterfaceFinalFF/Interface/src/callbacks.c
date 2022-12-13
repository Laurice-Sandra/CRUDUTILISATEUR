#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "election.h"
#include "connexion.h"
#include "lelectorale.h"
#include "observateur.h"
#include "bureauV.h"
char b[20];
char b1[20];
char c[20];
char c1[20];
observateur o;

int x = 1 ;
int y=1 ;
int check = 0 ;

int y,z,us[3]={0,0,0};

void
on_entry2_insert_text                  (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_entry3_insert_text                  (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_buttonConnecter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *identifiant,*motdepasse, *authentification , *role ,*output  ,*Administrateur,*ELECT,*OBS;
	GtkWidget *connecter;

char userid[20];
char pass1[20];
int role1;
char message[40];
connexion c ;
authentification=lookup_widget (objet,"Authentification");

connecter = lookup_widget (objet,"buttonConnecter");
identifiant = lookup_widget (objet,"entryIdentifiant");
motdepasse = lookup_widget (objet,"entryMotdepasse");
role = lookup_widget (objet,"spinbutton20");
output =lookup_widget (objet,"labelconnexion");
int a ;

strcpy(userid, gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(pass1, gtk_entry_get_text(GTK_ENTRY(motdepasse)));
role1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(role));
a=atoi(userid);

c=trouv_connexion(a,pass1,role1);
if(c.iduser==-1){
  sprintf(message,"Verifier votre identifiant ");
  gtk_label_set_text(GTK_LABEL(output),message);
 }
else 
    {
    if(strcmp(c.pass,"-1")==0)
      {
        sprintf(message,"Verifier votre mot de passe");
        gtk_label_set_text(GTK_LABEL(output),message);
      }
    else
        {
        if(c.role==4)
         {
	gtk_widget_destroy(authentification);
	Administrateur=create_Espace_Admin();
	gtk_widget_show(Administrateur);
	}
        
        if(c.role==1)
         {
	gtk_widget_destroy(authentification);
	ELECT=create_Espace_Electeur();
	gtk_widget_show(ELECT);
	}
        if(c.role==3)
         {
	gtk_widget_destroy(authentification);
	OBS=create_Gestion_Observateur();
	gtk_widget_show(OBS);
	}
         
       }
    }
}


void
on_buttonreour_userdecon_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *GU, *Eadmin;
	GU=lookup_widget(objet,"Gestion_utilisateur");
	gtk_widget_destroy(GU);
	Eadmin=create_Espace_Admin();
	gtk_widget_show(Eadmin);

}


void
on_treeviewAFFICHE_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_checkbuttonAGENTBV_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 	if(gtk_toggle_button_get_active((togglebutton)))
 { us[2]=1;}
}


void
on_checkbuttonOBSERVATEUR_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active((togglebutton)))
 { us[1]=1;}
}


void
on_checkbuttonELECTEUR_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active((togglebutton)))
 { us[0]=1;}
}


void
on_buttonAFFICH_CHOIX_USER_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *treeview;
	treeview = lookup_widget(objet,"treeviewAFFICHE");

        if(us[0]==1 && us[1]==0 && us[2]==0)
            {
            vider_supp(treeview);
            afficherelecteur(treeview);
            }
        else
            {
              if(us[0]==0 && us[1]==1 && us[2]==0) 
               {
                vider_supp(treeview);
                afficherobservateur(treeview);
               }
              else
                  {
                   if(us[0]==0 && us[1]==0 && us[2]==1)
		    {
		     vider_supp(treeview); 
		     afficheragent_bv(treeview);
		    }
                   else
		      {
			   vider_supp(treeview);
			   afficheruser(treeview); 
		      }
                  }
             }
}


void
on_radiobuttonHOMME_UTILISATEUR_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  y=2;
}


void
on_radiobuttonFEMME_UTILISATEUR_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  y=1;
}


void
on_buttonsAJOUT_utilisateur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *input0,*input1 ,*input2,*input3,*input4,*input5,*input6;
	  GtkWidget *output;
	  utilisateur u, w;
	  int x=0;
          char cin[10];
	  char sexe[5],ajout[30];
          if(y==1)
              strcpy(sexe,"F");
          if(y==2)
            strcpy(sexe,"H");
           
         input0 = lookup_widget(objet, "entryCIN") ;
	 input1 = lookup_widget(objet, "entryNOM") ;
	 input2 = lookup_widget(objet, "entryPRENOM") ;
	 input3 = lookup_widget(objet, "entryADRESSE") ;
         input4 =lookup_widget(objet, "spinbuttonroleajout") ;
         input5 =lookup_widget(objet, "spinbuttonAGE") ;
         input6 = lookup_widget(objet, "entryMAIL") ;
        
	 output = lookup_widget(objet, "labelVERIFAJOUT_U") ;
         strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input0)));
        

         int a;
          a = atoi ( cin );

         u.cin=a;

        u.role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.sexe,sexe);
        u.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
        
        strcpy(u.mail,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(u.nbv,"NUL");
        
        u.vote=-1;
	
        int v=1;
        
         if(u.cin==0)
           { v=0; }

         if(strcmp(u.sexe,"") == 0 )
             {v=0;}
         if(strcmp(u.nom,"") == 0 )
             {v=0;}
         if(strcmp(u.prenom,"") == 0 )
             {v=0;}
          if(strcmp(u.mail,"") == 0 )
              {v=0;}
         
         
    if(v==1)
       {
           w=chercher("utilisateur.txt", u.cin);
           if(w.cin ==-1)
                 x=ajouter("utilisateur.txt",u ); 
           verifier(x,ajout);
	   gtk_label_set_text(GTK_LABEL(output),ajout); 
        }
    else
         {
          sprintf(ajout,"Vérifier vos données !  ");
	 gtk_label_set_text(GTK_LABEL(output),ajout);
           }
          
         
        
 
}


void
on_buttonMODIF_UTILISA_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
  	 GtkWidget *input0,*input1,*input2,*input3,*input4,*input5,*input6;
  GtkWidget *output;
       utilisateur u,w;
       int x=0;
       char cin[8];
      char sexe[3],modif[50]="hey";
         if(z==1)
              strcpy(sexe,"F");
          if(z==2)
            strcpy(sexe,"H");



         input0 = lookup_widget(objet, "entrycin") ;
	 input1 = lookup_widget(objet, "entrynom_U") ;
	 input2 = lookup_widget(objet, "entryprenom_U") ;
	 input3 = lookup_widget(objet, "spinbutton2age") ;
	 input4 = lookup_widget(objet, "spinbuttonmodif_role_u");
	 input5 = lookup_widget(objet, "entryadresse_U") ;
         input6 = lookup_widget(objet, "entryMAIL_U");
         output = lookup_widget(objet, "labelVERIF_MOD_U") ;
         strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input0)));

       int a;
          a = atoi ( cin );

         u.cin=a;
        u.role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(u.sexe,sexe);
        u.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
        strcpy(u.mail,gtk_entry_get_text(GTK_ENTRY(input6)));

        w=chercher("utilisateur.txt",u.cin);

        strcpy(u.nbv,w.nbv);
        u.vote=w.vote;

        x=modifier( "utilisateur.txt",u);
         if(x==1)
           strcpy(modif,"modifier avec success");
        else 
           strcpy(modif,"echec modification");

        gtk_label_set_text(GTK_LABEL(output),modif); 

}


void
on_buttoncherche_modif_util_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 utilisateur u;
	 char cin1[8];
         char cin2[8];
	 char modif[25];
	 GtkWidget *input;
	 GtkWidget *output,*output1,*output2,*output3,*output4,*output5,*output6,*output7;

         output = lookup_widget(objet, "entrycin") ;
	 output1 = lookup_widget(objet, "entrynom_U") ;
	 output2 = lookup_widget(objet, "entryprenom_U") ;
	 output3 = lookup_widget(objet, "spinbutton2age") ;
	 output4 = lookup_widget(objet, "spinbuttonmodif_role_u");
	 output5 = lookup_widget(objet, "entryadresse_U") ;
         output6 = lookup_widget(objet, "entryMAIL_U");
         input = lookup_widget(objet, "entrycherche_modif_Utili");
         output7 = lookup_widget(objet, "labelVERIF_MOD_U") ;

         strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(input)));
        
        int b;
        b = atoi ( cin1 );
        
         
          


         u=chercher("utilisateur.txt", b);
         if(u.cin ==-1)
            strcpy(modif,"la cin est introuvable");
         else
             {  
                 strcpy(modif,"cin trouvé");
                 sprintf(cin2,"%d",u.cin);
                 gtk_entry_set_text(GTK_ENTRY(output),cin2);
                 gtk_entry_set_text(GTK_ENTRY(output1),u.nom);
                 gtk_entry_set_text(GTK_ENTRY(output2),u.prenom);
                 gtk_spin_button_set_value(GTK_SPIN_BUTTON(output3),u.age);
                 gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4),u.role);
                 gtk_entry_set_text(GTK_ENTRY(output5),u.adresse);
                 gtk_entry_set_text(GTK_ENTRY(output6),u.mail);
                 
        
             }
        gtk_label_set_text(GTK_LABEL(output7),modif);
   
}


void
on_radiobuttonhomme_U_MODIF_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  z=2;
}


void
on_radiobuttonfemme_U_MODIF_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  z=1;
}


void
on_treeviewsupp_utilis_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
        gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
	gchar* age;
	gchar* role;
	gchar* adresse;
        gchar* nbv;
        gchar* vote;
	gchar* mail;
        int cin1,age1,role1,vote1,x;
        utilisateur u,w;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&sexe,4,&age,5,&role,6,&adresse,7,&nbv,8,&vote,9,&mail,-1);
         cin1= atoi ( cin ) ;
         age1= atoi ( age ) ;
         role1= atoi( role );
         vote1= atoi( vote );
         u.cin = cin1;
         u.age = age1;
         u.role= role1;
         strcpy(u.nom,nom);
         strcpy(u.prenom,prenom);
         strcpy(u.sexe,sexe);
         strcpy(u.adresse,adresse);
         strcpy(u.mail,mail);
        x=supprimer("utilisateur.txt",u.cin);
        w=chercher("utilisateur.txt",u.cin);

        strcpy(u.nbv,w.nbv);
        u.vote=w.vote;
        if(x==1)
            vider_supp(treeview);
        else
         afficheruser_supp(treeview,u);

    }
}


void
on_buttoncherche_supp_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
 utilisateur w;
	 char cin1[8];
	 GtkWidget *treeview1, *input;
         treeview1 = lookup_widget(objet,"treeviewsupp_utilis");

         input  = lookup_widget(objet, "entrycherche_supp_utilisateur");
         strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(input)));
        
        int b;
        b = atoi ( cin1 );
        
        
          
         w=chercher("utilisateur.txt",b);
         if(w.cin !=-1)
             {
              
             afficheruser_supp(treeview1,w); 
              } 
         else
              vider_supp(treeview1); 

}


void
on_buttonROLE_AFFECT_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *combo, *input ,*output;
utilisateur u;

int n,i,j;
char cin[10],verif[50],tab[100][15];
  
  combo=lookup_widget(objet, "comboboxNUMBV_U");
  input = lookup_widget(objet, "entrycinaffectuser");
  output = lookup_widget(objet, "labelverif_affect") ;
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
 
     int a;
    a = atoi ( cin );

 u=chercher("utilisateur.txt",a);
  n=Nombrebv("bureauV.txt",tab);
  for(j=0;j<=n;j++)
  gtk_combo_box_remove_text(GTK_COMBO_BOX(combo),(j));
                          
    if(u.cin!=-1)
      {
        
	for(i=0;i<n;i++)
	   {gtk_combo_box_append_text(GTK_COMBO_BOX(combo),(tab[i]));}
       strcpy(verif,"cin trouvé");
         gtk_label_set_text(GTK_LABEL(output),verif);
      }
 
    else
        {
         strcpy(verif,"la cin inexistante");
         gtk_label_set_text(GTK_LABEL(output),verif);
        }
}


void
on_buttonAFFECT_UTILISATEUR_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *combo, *input ,*output;
utilisateur u;
int n;
char cin[10],verif[50],nbv[10];
  combo=lookup_widget(objet, "comboboxNUMBV_U");
  input = lookup_widget(objet, "entrycinaffectuser");
  output = lookup_widget(objet, "labelverif_affect") ;
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  strcpy(nbv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
 
     int a;
    a = atoi ( cin );

 
  n=affect("utilisateur.txt", a,nbv);
    if(n==1)
      {
         strcpy(verif,"Affectation avec success");
         gtk_label_set_text(GTK_LABEL(output),verif);
      }
 
    else
        {
         strcpy(verif,"Verifier la cin");
         gtk_label_set_text(GTK_LABEL(output),verif);
        }  
}


void
on_button_Ajouter_election_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id , *munic , *gov, *NombreBv , *nbH , *spinJ, *spinM , *spinA,*output;

	id = lookup_widget(objet,"entry1");
	munic = lookup_widget(objet,"entry2");
	gov = lookup_widget(objet,"comboboxGA");

	NombreBv = lookup_widget(objet,"entry4");
	nbH = lookup_widget(objet,"entry5");

	spinJ = lookup_widget(objet,"spinJA");
	spinM = lookup_widget(objet,"spinMA");
	spinA = lookup_widget(objet,"spinAA");


	output = lookup_widget(objet,"outputAdd");

	char message[200] ; 
	char BV[20],nombreH[20];

	election e ;
	
	int state = 1;

  
	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));

	if(strcmp(e.id,"") == 0 ){
		state = 0 ;
	}

	


	strcpy(e.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));

	if(strcmp(e.municipalite,"") == 0 ){
		state = 0 ;
	}

	strcpy(e.gov,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gov)));

	e.nombreBV = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(NombreBv));

	strcpy(nombreH,gtk_entry_get_text(GTK_ENTRY(nbH)));
	e.nbHabitants = atoi(nombreH) ; 
	

	e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJ));
	e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinM));
	e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinA));

	if(x == 1){
		strcpy(e.type,"Presidentielle");
	}
	else if(x == 2){
		strcpy(e.type,"Municipale");
	}
	else{
		strcpy(e.type,"Legislative");
	}

	if(check == 0){
		sprintf(message,"Svp Confirmer votre choix ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		if(rechercher_election(e.id)){
			sprintf(message,"Id déja exist ! ");
			gtk_label_set_text(GTK_LABEL(output),message);

			
		}
		else{
			if(!state){
				sprintf(message,"Vérifier vos données !  ");
				gtk_label_set_text(GTK_LABEL(output),message);
			}
			else{
				sprintf(message,"Votre ajout a été effectué avec succés ! ");
				gtk_label_set_text(GTK_LABEL(output),message);

				ajouter_election(e);
			}

		}
	}

}


void
on_radioLegA_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		x = 3 ;
	}

}


void
on_municipaleA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		x = 2 ;
	}

}


void
on_radioPA_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		x = 1 ;
	}

}


void
on_checkadd_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		check = 1;
	}
	else{
		check = 0; 
	}
}


void
on_chercherElection_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id , *munic , *gov,*type, *NombreBv , *nbH , *spinJ, *spinM , *spinA , *output;
	
	char message[200];
	char idElection[20];


	election e;

	id = lookup_widget(objet,"idEdit");

	munic = lookup_widget(objet,"entry6");
	gov = lookup_widget(objet,"entry7");

	NombreBv = lookup_widget(objet,"entry8");
	nbH = lookup_widget(objet,"entry9");

	spinJ = lookup_widget(objet,"spinJ");
	spinM = lookup_widget(objet,"spinM");
	spinA = lookup_widget(objet,"spinA");



	output = lookup_widget(objet,"outputEdit");

	strcpy(idElection,gtk_entry_get_text(GTK_ENTRY(id)));


	if(!rechercher_election(idElection)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{		
		strcpy(e.municipalite,trouver_election(idElection).municipalite);

		strcpy(e.type,trouver_election(idElection).type);
		
		strcpy(e.gov,trouver_election(idElection).gov);

		e.nombreBV = trouver_election(idElection).nombreBV ;


		e.nbHabitants = trouver_election(idElection).nbHabitants;

		e.d = trouver_election(idElection).d ; 

		
			
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		
		
    		gtk_entry_set_text(GTK_ENTRY(munic),e.municipalite);



		int comboValue = 0;
		if(strcmp(e.gov,"Ariana") == 0 ){
			comboValue = 1;
		}

		gtk_combo_box_set_active(GTK_COMBO_BOX(gov),comboValue);
                ;
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(NombreBv),e.nombreBV);

		char nombreHabitants[20];
		sprintf(nombreHabitants,"%d",e.nbHabitants);
		
		gtk_entry_set_text(GTK_ENTRY(nbH),nombreHabitants);

		gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinJ),e.d.j);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinM),e.d.m);

		gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinA),e.d.a);


		}


}


void
on_radioPM_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		y = 1 ;
	}
}


void
on_radioMunicM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		y = 2 ;
	}
}


void
on_radiobuttonLegim_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton)){
		y = 3 ;
	}
}


void
on_buttonModifa_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id , *munic , *gov, *NombreBv , *nbH , *spinJ, *spinM , *spinA , *output;
	
	char message[200];
	char idElection[20];


	election e;

	id = lookup_widget(objet,"idEdit");

	munic = lookup_widget(objet,"entry6");
	gov = lookup_widget(objet,"entry7");

	NombreBv = lookup_widget(objet,"entry8");
	nbH = lookup_widget(objet,"entry9");

	spinJ = lookup_widget(objet,"spinJ");
	spinM = lookup_widget(objet,"spinM");
	spinA = lookup_widget(objet,"spinA");



	output = lookup_widget(objet,"outputEdit");

	strcpy(idElection,gtk_entry_get_text(GTK_ENTRY(id)));


	if(!rechercher_election(idElection)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		char BV[20],nombreH[20];
				
		strcpy(e.id,idElection); 
		strcpy(e.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));

		strcpy(e.gov,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gov)));

		e.nombreBV = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(NombreBv));

		strcpy(nombreH,gtk_entry_get_text(GTK_ENTRY(nbH)));
		e.nbHabitants = atoi(nombreH) ; 


		e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJ));
		e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinM));
		e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinA));
		

		if(y == 1){
			strcpy(e.type,"Presidentielle");
		}
		else if(y == 2){
			strcpy(e.type,"Municipale");
		}
		else{
			strcpy(e.type,"Legislative");
		}
				
		sprintf(message,"Votre Modification avec succés !\n");
		gtk_label_set_text(GTK_LABEL(output),message);

		modifier_election(e);
		

	}
}


void
on_Refresh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *treeview;
	treeview = lookup_widget(objet,"treeviewE");

	afficher_election(treeview);

}


void
on_supprimerElection_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id , *output;
	char message[200];
	char idElection[20];

	id = lookup_widget(objet,"idSupp");
	strcpy(idElection,gtk_entry_get_text(GTK_ENTRY(id)));




	output = lookup_widget(objet,"outputSup");

	if(rechercher_election(idElection)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
		supprimer_election(idElection);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}


void
on_buttonretoura_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

 GtkWidget *GE, *Eadmin;
	GE=lookup_widget(objet,"Gestion_des_elections");
	gtk_widget_destroy(GE);
	Eadmin=create_Espace_Admin();
	gtk_widget_show(Eadmin);

}


void
on_buttond__connect_ala_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *OBS, *AUTH;
     OBS=lookup_widget(objet,"Gestion_Observateur");
     gtk_widget_destroy(OBS);
     AUTH=create_Authentification();
     gtk_widget_show(AUTH);   
}


void
on_treeview_hadil_afficher_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
gchar*Date;
char date[30];
observateur o;

sprintf(date,"%d %d %d",o.d.j,o.d.m,o.d.a);




treeview1=lookup_widget("Gestion_Observateur",treeview1);

afficher_obs(treeview1);

}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button21_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
observateur o;
int a=0;
date d;
GtkWidget *input1, *input2,*input3,*input4,*input5 ;
GtkWidget *window2aj;
GtkWidget *jour, *mois, *annee;
window2aj=lookup_widget(objet,"Gestion_Observateur");
jour=lookup_widget(GTK_WIDGET(objet),"spinbutton1jour");
mois=lookup_widget(GTK_WIDGET(objet),"spinbutton2mois");
annee=lookup_widget(GTK_WIDGET(objet),"spinbutton3annee");
o.d.j=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.d.m=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.d.a=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");
input3=lookup_widget(objet,"entry8");
input4=lookup_widget(objet,"entry9");
input5=lookup_widget(objet,"entry11");
//orientation=lookup_widget(objet, "comboboxentry1");
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.ville,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.nationalite,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(o.genre,b);
if (a==0)
{ajouter_obs(o);}

}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *GU, *Eadmin;
	Eadmin=lookup_widget(objet,"Espace_Admin");
	gtk_widget_destroy(Eadmin);
	GU=create_Gestion_utilisateur();
	gtk_widget_show(GU);
}


void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_ala_modif_femme_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button3retou_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_radiobutton_ala_modifier_homme_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_ala_confirmer_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_ala_supprimer_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonD__connexion_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Authen, *Eadmin;
Eadmin=lookup_widget(objet,"Espace_Admin");
gtk_widget_destroy(Eadmin);
Authen=create_Authentification();
gtk_widget_show(Authen);
}


void
on_buttonStatistiqueAdmin_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *stat, *Eadmin;
	Eadmin=lookup_widget(objet,"Espace_Admin");
	gtk_widget_destroy(Eadmin);
	stat=create_Statistique1();
	gtk_widget_show(stat);

}


void
on_buttonGBV_gestion_bureau_de_vote_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *GBV, *Eadmin;
	Eadmin=lookup_widget(objet,"Espace_Admin");
	gtk_widget_destroy(Eadmin);
	GBV=create_GESTION_DE_BV();
	gtk_widget_show(GBV);
}


void
on_buttonGE_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *GE, *Eadmin;
	Eadmin=lookup_widget(objet,"Espace_Admin");
	gtk_widget_destroy(Eadmin);
	GE=create_Gestion_des_elections();
	gtk_widget_show(GE);
}


void
on_button43_deconnexion_espace_electeur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button4GLE                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *GLE, *EE;
	EE=lookup_widget(objet,"Espace_Electeur");
	gtk_widget_destroy(EE);
	GLE=create_gestion_liste_electorale();
	gtk_widget_show(GLE);
}


void
on_button_vote_electeur                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *GV, *EE;
	EE=lookup_widget(objet,"Espace_Electeur");
	gtk_widget_destroy(EE);
	GV=create_windowvote();
	gtk_widget_show(GV);
}


void
on_accueilListeE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *GLE, *EE;
	GLE=lookup_widget(objet,"gestion_liste_electorale");
	gtk_widget_destroy(GLE);
	EE=create_Espace_Electeur();
	gtk_widget_show(EE);
}


void
on_buttonafficherliste_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview ;

	treeview = lookup_widget(objet,"treeview1liste");
	afficher_listeE(treeview,"listeE.txt");
}


void
on_buttoninserezliste_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *idL , *idT , *idM1 , *idM2 , *idM3 , *spinJD , *spinMD , *spinAD, *spinJF , *spinMF , *spinAF ;

	Lelectoral l;
	
	idL = lookup_widget(objet,"id_liste");
	l.idListe = atoi(gtk_entry_get_text(GTK_ENTRY(idL)));

	idT = lookup_widget(objet,"id_tete");
	l.idTete = atoi(gtk_entry_get_text(GTK_ENTRY(idT)));

	idM1 = lookup_widget(objet,"id_membrei");
	strcpy(l.idM1,gtk_entry_get_text(GTK_ENTRY(idM1)));

	idM2 = lookup_widget(objet,"id_membreii");
	strcpy(l.idM2,gtk_entry_get_text(GTK_ENTRY(idM2)));

	idM3 = lookup_widget(objet,"id_membreiii");
	strcpy(l.idM3,gtk_entry_get_text(GTK_ENTRY(idM3)));


	// Date debut 
	spinJD = lookup_widget(objet,"spinbutton_debut_j");
	spinMD = lookup_widget(objet,"spinbutton_debut_m");
	spinAD = lookup_widget(objet,"spinbutton_debut_a");

	l.d_debut.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJD));
	l.d_debut.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinMD));
	l.d_debut.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinAD));

	// Date Fin 
	spinJF = lookup_widget(objet,"spinbutton_fin_j");
	spinMF = lookup_widget(objet,"spinbutton_fin_m");
	spinAF = lookup_widget(objet,"spinbutton_fin_a");

	l.d_fin.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJF));
	l.d_fin.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinMF));
	l.d_fin.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinAF));


	l.nbrVote = 0;

	//Ajout du liste dans le fichier 

	ajouterliste(l);
}


void
on_button_chercher_modifier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *idL , *idT , *idM1 , *idM2 , *idM3 , *spinJD , *spinMD , *spinAD, *spinJF , *spinMF , *spinAF ;

	Lelectoral l;
	
	idL = lookup_widget(objet,"id_modifier");
	idT = lookup_widget(objet,"new_tete");
	l.idListe = atoi(gtk_entry_get_text(GTK_ENTRY(idL)));

	if(rechercher_listeE(l.idListe) == 1){
	
	char text[30];
	sprintf(text,"%d",recherche_listeE(l.idListe).idTete);
		
	gtk_entry_set_text(GTK_ENTRY(idT),text);	
	idM1 = lookup_widget(objet,"new_membrei");
	gtk_entry_set_text(GTK_ENTRY(idM1),recherche_listeE(l.idListe).idM1);

	idM2 = lookup_widget(objet,"new_membreii");
	gtk_entry_set_text(GTK_ENTRY(idM2),recherche_listeE(l.idListe).idM2);

	idM3 = lookup_widget(objet,"new_membreiii");
	gtk_entry_set_text(GTK_ENTRY(idM3),recherche_listeE(l.idListe).idM3);


	// Date debut 
	spinJD = lookup_widget(objet,"spinbutton_new_debut_j");

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinJD),recherche_listeE(l.idListe).d_debut.j);

	spinMD = lookup_widget(objet,"spinbutton_new_debut_m");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinMD),recherche_listeE(l.idListe).d_debut.m);

	spinAD = lookup_widget(objet,"spinbutton_new_debut_a");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinAD),recherche_listeE(l.idListe).d_debut.a);

	// Date Fin 
	spinJF = lookup_widget(objet,"spinbutton_new_fin_j");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinJF),recherche_listeE(l.idListe).d_fin.j);

	spinMF = lookup_widget(objet,"spinbutton_new_fin_m");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinMF),recherche_listeE(l.idListe).d_fin.m);


	spinAF = lookup_widget(objet,"spinbutton_new_fin_a");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinAF),recherche_listeE(l.idListe).d_fin.a);


	}
}


void
on_button_confirmer_modifier_liste_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *idL , *idT , *idM1 , *idM2 , *idM3 , *spinJD , *spinMD , *spinAD, *spinJF , *spinMF , *spinAF ;

	Lelectoral l;
	
	idL = lookup_widget(objet,"id_modifier");
		
	l.idListe = atoi(gtk_entry_get_text(GTK_ENTRY(idL)));

	if(rechercher_listeE(l.idListe) == 1){

		idT = lookup_widget(objet,"new_tete");
		l.idTete = atoi(gtk_entry_get_text(GTK_ENTRY(idT)));

		idM1 = lookup_widget(objet,"new_membrei");
		strcpy(l.idM1,gtk_entry_get_text(GTK_ENTRY(idM1)));

		idM2 = lookup_widget(objet,"new_membreii");
		strcpy(l.idM2,gtk_entry_get_text(GTK_ENTRY(idM2)));

		idM3 = lookup_widget(objet,"new_membreiii");
		strcpy(l.idM3,gtk_entry_get_text(GTK_ENTRY(idM3)));


		// Date debut 
		spinJD = lookup_widget(objet,"spinbutton_new_debut_j");
		spinMD = lookup_widget(objet,"spinbutton_new_debut_m");
		spinAD = lookup_widget(objet,"spinbutton_new_debut_a");

		l.d_debut.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJD));
		l.d_debut.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinMD));
		l.d_debut.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinAD));

		// Date Fin 
		spinJF = lookup_widget(objet,"spinbutton_new_fin_j");
		spinMF = lookup_widget(objet,"spinbutton_new_fin_m");
		spinAF = lookup_widget(objet,"spinbutton_new_fin_a");

		l.d_fin.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinJF));
		l.d_fin.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinMF));
		l.d_fin.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinAF));


		l.nbrVote = recherche_listeE(l.idListe).nbrVote;

		//Modifier du liste dans le fichier 

		modifier_listeE(l);

	}
}


void
on_button_supprimer_liste_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id ;
	id = lookup_widget(objet,"id_supprimer");

	int idListe = atoi(gtk_entry_get_text(GTK_ENTRY(id)));

	supprimerliste(idListe);
}


void
on_radiobuttonchoixliste1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonchoixliste3_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonvoteblanc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonchoixliste2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonretourvote_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *GV, *EE;
	GV=lookup_widget(objet,"windowvote");
	gtk_widget_destroy(GV);
	EE=create_Espace_Electeur();
	gtk_widget_show(EE);
}


void
on_buttonconfirmervote_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttondretourstatistique_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_radioEcoleA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		x=1;
}


void
on_radioCollegeA_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		x=2;
}


void
on_radioLyceeA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		x=3;
}


void
on_ajouterBV_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 // HO : horaire Ouverture HF : fermeture
	//idAB : id agent bureau
	GtkWidget *id, *etab , *nombreSalle , *Irie , *deleg , *codePostal , *HO , *HF , *idAB, *output;
	bureauV b ;

	id = lookup_widget(objet,"bv1");
	strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(id)));

	etab = lookup_widget(objet,"bv2");
	strcpy(b.etabl,gtk_entry_get_text(GTK_ENTRY(etab)));

	if(x == 1){
		strcpy(b.typeE,"Ecole");
	}else if(x == 2){
		strcpy(b.typeE,"College");
	}else{
		strcpy(b.typeE,"Lycee");
	}

	nombreSalle = lookup_widget(objet,"bv3");
	b.nbS = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombreSalle));

	Irie = lookup_widget(objet,"bv4");
	strcpy(b.Irie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Irie)));
	
	deleg = lookup_widget(objet,"bv5");
	strcpy(b.deleg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	

	char code[20] ;
	codePostal = lookup_widget(objet,"bv6");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(codePostal)));
	// atoi(ch) : convertir ch => int
	b.codeP = atoi(code) ; 

	HO = lookup_widget(objet,"bv7");
	b.HoraireO = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(HO));

	HF = lookup_widget(objet,"bv8");
	b.HoraireF = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(HF));


	char idAgentB[30];
	idAB = lookup_widget(objet,"bv9");
	strcpy(idAgentB,gtk_entry_get_text(GTK_ENTRY(idAB)));
	b.idAgentB = atoi(idAgentB);

	output = lookup_widget(objet,"outputABV");
	char message[200];
	if(rechercher_bureauV(b.id) == 1){
		sprintf(message,"Id Déja existe");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Votre ajout a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);

		ajouter_bureauV(b);
	}
}


void
on_checkAjBV_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton))
		check = 1;
	else 
		check = 0 ;
}


void
on_rechercherBV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id, *etab , *nombreSalle , *Irie , *deleg , *codePostal , *HO , *HF , *idAB, *output;

	char message[200] ;
	bureauV b;

	id = lookup_widget(objet,"bvM1");
	strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(id)));

	output = lookup_widget(objet,"outputModifBV");


	if(!rechercher_bureauV(b.id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{	

		nombreSalle = lookup_widget(objet,"bvM2");
		gtk_spin_button_set_value(nombreSalle,trouverBureauV(b.id).nbS);


		char oldIrie[30];
		strcpy(oldIrie,trouverBureauV(b.id).Irie);
		

		//Tunis 1 => 0 value (combobox) 
		//Nabeul_2 => 1 value (combobox)
		//Ariana => 2 value (combobox)
		
		Irie = lookup_widget(objet,"bvM3");
		int comboIndex = 0 ;

		if(strcmp(oldIrie,"Nabeul_2") == 0){
			comboIndex = 1 ;
		}else if(strcmp(oldIrie,"Ariana") == 0){
			comboIndex = 2 ;
		}

		gtk_combo_box_set_active(Irie,comboIndex);
		
		
		
		deleg = lookup_widget(objet,"bvM4");
		
		//Ariana_ville
		//Raoued_1
		//Mnihla
		//Sidi_hssin
		//Haawriya
		//Hammamet		
		
		comboIndex = 0 ;
		char oldDeleg[30];
		strcpy(oldDeleg,trouverBureauV(b.id).deleg);

		if(strcmp(oldDeleg,"Raoued_1") == 0){
			comboIndex = 1 ;
		}else if(strcmp(oldDeleg,"Mnihla") == 0){
			comboIndex = 2 ;
		}else if(strcmp(oldDeleg,"Sidi_hssin") == 0){
			comboIndex = 3 ;
		}else if(strcmp(oldDeleg,"Mnihla") == 0){
			comboIndex = 4 ;
		}else if(strcmp(oldDeleg,"Haawriya") == 0){
			comboIndex = 5 ;
		}else if(strcmp(oldDeleg,"Hammamet") == 0){
			comboIndex = 6 ;
		}

		gtk_combo_box_set_active(deleg,comboIndex);		

		
		codePostal = lookup_widget(objet,"bvM5");
		char code[30];
		sprintf(code,"%d",trouverBureauV(b.id).codeP);
		gtk_entry_set_text(GTK_ENTRY(codePostal),code);
		
		HO = lookup_widget(objet,"bvM6");
		gtk_spin_button_set_value(HO,trouverBureauV(b.id).HoraireO);
		

		HF = lookup_widget(objet,"bvM7");
		gtk_spin_button_set_value(HF,trouverBureauV(b.id).HoraireF);

	
		idAB = lookup_widget(objet,"bvM8");
		char idAgent[30];
		sprintf(idAgent,"%d",trouverBureauV(b.id).idAgentB);
		gtk_entry_set_text(GTK_ENTRY(idAB),idAgent);

		etab = lookup_widget(objet,"bvM9");
		gtk_entry_set_text(GTK_ENTRY(etab),trouverBureauV(b.id).etabl);

		
			
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		


	}
}


void
on_radioEcoleM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton))
		y=1;
}


void
on_radioCollegeM_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton))
		y=2;
}


void
on_radioLyceeM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if(gtk_toggle_button_get_active(togglebutton))
		y=3;
}


void
on_enregistrerModifBV_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *id, *etab , *nombreSalle , *Irie , *deleg , *codePostal , *HO , *HF , *idAB, *output;
	bureauV b ;

	id = lookup_widget(objet,"bvM1");
	strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(id)));

	etab = lookup_widget(objet,"bvM9");
	strcpy(b.etabl,gtk_entry_get_text(GTK_ENTRY(etab)));

	if(y == 1){
		strcpy(b.typeE,"Ecole");
	}else if(y == 2){
		strcpy(b.typeE,"College");
	}else{
		strcpy(b.typeE,"Lycee");
	}

	nombreSalle = lookup_widget(objet,"bvM2");
	b.nbS = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombreSalle));

	Irie = lookup_widget(objet,"bvM3");
	strcpy(b.Irie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Irie)));
	
	deleg = lookup_widget(objet,"bvM4");
	strcpy(b.deleg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	

	char code[20] ;
	codePostal = lookup_widget(objet,"bvM5");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(codePostal)));
	// atoi(ch) : convertir ch => int
	b.codeP = atoi(code) ; 

	HO = lookup_widget(objet,"bvM6");
	b.HoraireO = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(HO));

	HF = lookup_widget(objet,"bvM7");
	b.HoraireF = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(HF));


	char idAgentB[30];
	idAB = lookup_widget(objet,"bvM8");
	strcpy(idAgentB,gtk_entry_get_text(GTK_ENTRY(idAB)));
	b.idAgentB = atoi(idAgentB);

	output = lookup_widget(objet,"outputModifBV");
	char message[200];
	
	if(!rechercher_bureauV(b.id)){
		sprintf(message,"Verifier vos informations \n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		modifier_bureauV(b);		
		sprintf(message,"Votre Bureau de vote a été modifié avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
	}
}


void
on_supprimerBV_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *idBv , *output ;
	char message[200];

	idBv = lookup_widget(objet,"idSuppBV");
	output = lookup_widget(objet,"outputSuppBV");


	char idSupp[20] ;
	strcpy(idSupp,gtk_entry_get_text(GTK_ENTRY(idBv)));

	if(rechercher_bureauV(idSupp) == 1){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
		supprimer_bureauV(idSupp);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}	
 
}


void
on_afficherListeBV_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *treeview ;
	treeview = lookup_widget(objet,"treeviewBV");
	afficher_bureauV(treeview);
}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget  *output;
	 char verif[50];
         char tauxh[20];
         char tauxf[20];
	float tph,tpf;
	
        
       output =lookup_widget (objet,"TauxPHF");

	TPHF("utilisateur.txt",&tph,&tpf);

      if(tph==-1)
      {
      strcpy(verif," aucun homme participant ");
       gtk_label_set_text(GTK_LABEL(output),verif);
       }
      else
       {
          if(tpf==-1)
	      {
	      strcpy(verif," aucune femme  participante ");
	       gtk_label_set_text(GTK_LABEL(output),verif);
	       }
         else
              {
		sprintf(tauxh,"%.3f",tph);
                sprintf(tauxf,"%.3f",tpf);
		strcat(tauxh,"%");
                strcat(tauxf,"%");
                strcpy(verif,"TPH: ");
                strcat(verif,tauxh);
                strcat(verif," TPF:");
                strcat(verif,tauxf);

                
	       gtk_label_set_text(GTK_LABEL(output),verif);
               }
      }
}


void
on_TAUXpe_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

 GtkWidget  *output;
	 char taux[50];
	float t;
	
        
       output =lookup_widget (objet,"Tauxpe");

	t= TPE("utilisateur.txt");

      if(t==-1)
      {
       strcpy(taux,"Aucun électeur!");
       gtk_label_set_text(GTK_LABEL(output),taux);
       }
      else
       {
        sprintf(taux,"%.3f",t);
        strcat(taux,"%");
       gtk_label_set_text(GTK_LABEL(output),taux);
       }
 
      
}


void
on_AgeEP_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *output;
	 char taux[50];
	float t;
	
        
       output =lookup_widget (objet,"AgeMEP");

	t=agemoyen("utilisateur.txt");

      if(t==-1)
      {
       strcpy(taux,"aucun électeur participant");
       gtk_label_set_text(GTK_LABEL(output),taux);
       }
      else
       {
        sprintf(taux,"%.3f",t);
       gtk_label_set_text(GTK_LABEL(output),taux);
       }
}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
       /*GtkWidget *treeview;
       treeview = lookup_widget(objet,"treeview08");
       afficher_nb_electeurs_bv(treeview);*/
}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonretour_stat_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *stat, *Eadmin;
	stat=lookup_widget(objet,"Statistique1");
	gtk_widget_destroy(stat);
	Eadmin=create_Espace_Admin();
	gtk_widget_show(Eadmin);
}

