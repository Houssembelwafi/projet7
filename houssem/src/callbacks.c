#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "stdlib.h"
#include "election.h"


int x = 1 ;
int y = 1 ; 

int check = 0 ; 

/* ---------------------------- INTERFACE MENU ------------------------------- */

void
on_toStats_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ; 
	
	window1 = create_stats ();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toVote_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_vote();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toModLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_modifier_liste ();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toAffLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_afficher_liste_electorale ();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toAddLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_ajout_liste ();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toSupprimerListe_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_supprimer_liste();
	window2 = lookup_widget(objet,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_radiobuttonAG_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=1;
	}
}


void
on_radiobuttonAC_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_radiobuttonAD_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=3;
	}
}


void
on_ajouterLE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nomLE, *idLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 , *output,*j,*m,*a  ;
GtkWidget *munic ; 
	
	election e;
	char message[200];
	
	
	
	
	idLE=lookup_widget(objet,"idLE");
	nomLE=lookup_widget(objet,"nomLE");

	munic = lookup_widget(objet,"comboboxMunic");

	nomCT=lookup_widget(objet,"nomCT");
	cinCT=lookup_widget(objet,"cinT");

	nomC1=lookup_widget(objet,"nomC1");
	cinC1=lookup_widget(objet,"cinC1");

	nomC2=lookup_widget(objet,"nomC2");
	cinC2=lookup_widget(objet,"cinC2");

	nomC3=lookup_widget(objet,"nomC3");
	cinC3=lookup_widget(objet,"cinC3");

	j = lookup_widget(objet,"spinJA");
	m = lookup_widget(objet,"spinMA");
	a = lookup_widget(objet,"spinAA");

	output = lookup_widget(objet,"outputLE");



	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

	strcpy(e.munic,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));

	strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
	strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

	strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
	strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

	strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
	strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

	strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
	strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



	if(x==1){
		strcpy(e.orientation,"gauche");	
	}
	else if(x == 2){
		strcpy(e.orientation,"center");
	}
	else{
		strcpy(e.orientation,"droite");
	}

	

	e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

	e.nbrVote = 0 ;
	 
	if(rechercher_election(e.id)){
		sprintf(message,"id déja exist ! \n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		ajouter(e);		
		sprintf(message,"Votre ajout a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
	}
	
}


void
on_afficherLE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewLE");
		
	afficher_election(treeview,"election.txt");
}


void
on_radiobuttonGE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=1;
	}
}


void
on_radiobuttonCE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}
}


void
on_radiobuttonDE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=3;
	}
}


void
on_consulterLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
	GtkWidget *j , *m , *a ;
	GtkWidget * munic ; 
	
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(objet,"outputLEE");	
	

	if(!rechercher_election(id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		election e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_election(id).nom);
		strcpy(e.orientation,recherche_election(id).orientation);

		strcpy(e.nomCT,recherche_election(id).nomCT);
		strcpy(e.cinT,recherche_election(id).cinT);

		strcpy(e.nomC1,recherche_election(id).nomC1);
		strcpy(e.cinC1,recherche_election(id).cinC1);

		strcpy(e.nomC2,recherche_election(id).nomC2);
		strcpy(e.cinC2,recherche_election(id).cinC2);

		strcpy(e.nomC3,recherche_election(id).nomC3);
		strcpy(e.cinC3,recherche_election(id).cinC3);
		strcpy(e.munic,recherche_election(id).munic);

		int comboValue = 0 ;
		

		if(strcmp(e.munic,"Raoued") == 0){
			comboValue = 1 ;
		}
		else if(strcmp(e.munic,"NourJaafer") == 0){
			comboValue = 2 ;
		}
		munic = lookup_widget(objet,"combobox2");

		gtk_combo_box_set_active(munic,comboValue);

		


					
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		

		nomLE=lookup_widget(objet,"nomLEE");
    		gtk_entry_set_text(GTK_ENTRY(nomLE),e.nom);

		nomCT=lookup_widget(objet,"nomCTE");
		gtk_entry_set_text(GTK_ENTRY(nomCT),e.nomCT);

		cinCT=lookup_widget(objet,"cinTE");
		gtk_entry_set_text(GTK_ENTRY(cinCT),e.cinT);

		nomC1=lookup_widget(objet,"nomCE1");
		gtk_entry_set_text(GTK_ENTRY(nomC1),e.nomC1);

		cinC1=lookup_widget(objet,"cinCE1");
		gtk_entry_set_text(GTK_ENTRY(cinC1),e.cinC1);

		nomC2=lookup_widget(objet,"nomCE2");
		gtk_entry_set_text(GTK_ENTRY(nomC2),e.nomC2);

		cinC2=lookup_widget(objet,"cinCE2");
		gtk_entry_set_text(GTK_ENTRY(cinC2),e.cinC2);


		nomC3=lookup_widget(objet,"nomCE3");
		gtk_entry_set_text(GTK_ENTRY(nomC3),e.nomC3);

		cinC3=lookup_widget(objet,"cinCE3");
		gtk_entry_set_text(GTK_ENTRY(cinC3),e.cinC3);

		j = lookup_widget(objet,"spinJM");
		gtk_spin_button_set_value(j,recherche_election(id).d.j);


		m = lookup_widget(objet,"spinMM");
		gtk_spin_button_set_value(m,recherche_election(id).d.m);

		a = lookup_widget(objet,"spinAM");
		gtk_spin_button_set_value(a,recherche_election(id).d.a);

		
	}
}


void
on_saveChangesLE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
GtkWidget *munic ; 

	GtkWidget *idLE , *output;
	char message[200];
	char id[20];
	election e;

	idLE = lookup_widget(objet,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(objet,"outputLEE");

	if(check == 0 ){
		sprintf(message,"SVP confirmer votre choix ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		if(rechercher_election(id)){
		nomLE=lookup_widget(objet,"nomLEE");
		nomCT=lookup_widget(objet,"nomCTE");
		cinCT=lookup_widget(objet,"cinTE");

		nomC1=lookup_widget(objet,"nomCE1");
		cinC1=lookup_widget(objet,"cinCE1");

		nomC2=lookup_widget(objet,"nomCE2");
		cinC2=lookup_widget(objet,"cinCE2");

		nomC3=lookup_widget(objet,"nomCE3");
		cinC3=lookup_widget(objet,"cinCE3");

		munic = lookup_widget(objet,"combobox2");

		strcpy(e.munic,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));

		strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
		strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

		strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
		strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

		strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
		strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

		strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
		strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

		strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
		strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



		if(y==1){
			strcpy(e.orientation,"gauche");	
		}
		else if(y == 2){
			strcpy(e.orientation,"center");
		}
		else{
			strcpy(e.orientation,"droite");
		}


		GtkWidget *j,*m,*a; 
		j = lookup_widget(objet,"spinJM");
		m = lookup_widget(objet,"spinMM");
		a = lookup_widget(objet,"spinAM");
	

		e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
		e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
		e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

		e.nbrVote = recherche_election(id).nbrVote ; 

		sprintf(message,"Votre modification a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_election(e);
		
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}

	}
}


void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active (togglebutton)){
		check = 1 ;
	}
	else{
		check = 0 ;
	}
}


void
on_voter_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idLE , *output ; 
	char id[30];
	char message[100] ;  

	idLE = lookup_widget(objet,"idVote");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	
	output = lookup_widget(objet,"outputVote");

	if(rechercher_election(id)){
		election e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_election(id).nom);
		strcpy(e.orientation,recherche_election(id).orientation);

		strcpy(e.nomCT,recherche_election(id).nomCT);
		strcpy(e.cinT,recherche_election(id).cinT);

		strcpy(e.nomC1,recherche_election(id).nomC1);
		strcpy(e.cinC1,recherche_election(id).cinC1);

		strcpy(e.nomC2,recherche_election(id).nomC2);
		strcpy(e.cinC2,recherche_election(id).cinC2);

		strcpy(e.nomC3,recherche_election(id).nomC3);
		strcpy(e.cinC3,recherche_election(id).cinC3);
		strcpy(e.munic,recherche_election(id).munic);

		e.d.j = recherche_election(id).d.j ;
		e.d.m = recherche_election(id).d.m ;
		e.d.a = recherche_election(id).d.a ;

		e.nbrVote = recherche_election(id).nbrVote + 1 ; 
		modifier_election(e);
		sprintf(message,"Vote ajouté avec succés  ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}


void
on_refreshTreeView_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewVote");
		
	afficher_election(treeview,"election.txt");
}


void
on_refreshStat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewStat2");
	trierLE(treeview,"election.txt");
}


void
on_refreshStat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewStat1");
		
	afficher_electionVote(treeview);
}


void
on_supListe_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idSupp");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));


	output = lookup_widget(objet,"outputSupp");

	if(rechercher_election(id)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
		
	supprimer(id);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}


void
on_retourAJ_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"ajout_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourAff_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"afficher_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourModif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"modifier_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourVote_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"vote");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourStats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"stats");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourSupp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(objet,"supprimer_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}

