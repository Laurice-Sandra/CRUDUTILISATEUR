#include <gtk/gtk.h>


void
on_entry2_insert_text                  (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data);

void
on_entry3_insert_text                  (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data);

void
on_buttonConnecter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonreour_userdecon_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewAFFICHE_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbuttonAGENTBV_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonOBSERVATEUR_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonELECTEUR_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAFFICH_CHOIX_USER_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonHOMME_UTILISATEUR_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonFEMME_UTILISATEUR_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonsAJOUT_utilisateur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonMODIF_UTILISA_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoncherche_modif_util_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonhomme_U_MODIF_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemme_U_MODIF_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewsupp_utilis_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttoncherche_supp_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonROLE_AFFECT_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAFFECT_UTILISATEUR_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_Ajouter_election_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioLegA_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_municipaleA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioPA_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkadd_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_chercherElection_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioPM_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioMunicM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonLegim_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonModifa_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Refresh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimerElection_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretoura_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttond__connect_ala_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_hadil_afficher_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button19_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button21_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ala_modif_femme_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button3retou_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_ala_modifier_homme_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ala_confirmer_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ala_supprimer_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonD__connexion_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonStatistiqueAdmin_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonGBV_gestion_bureau_de_vote_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonGE_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button43_deconnexion_espace_electeur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4GLE                          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_vote_electeur                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_accueilListeE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonafficherliste_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttoninserezliste_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_chercher_modifier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_confirmer_modifier_liste_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_liste_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonchoixliste1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonchoixliste3_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonvoteblanc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonchoixliste2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonretourvote_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonconfirmervote_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttondretourstatistique_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioEcoleA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioCollegeA_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioLyceeA_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouterBV_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkAjBV_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rechercherBV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radioEcoleM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioCollegeM_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioLyceeM_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_enregistrerModifBV_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimerBV_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherListeBV_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_TAUXpe_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_AgeEP_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretour_stat_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);
