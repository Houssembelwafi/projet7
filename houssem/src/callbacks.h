#include <gtk/gtk.h>


void
on_toStats_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toVote_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toModLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toAffLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toAddLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toSupprimerListe_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonAG_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAC_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAD_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouterLE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherLE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonGE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonCE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonDE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_consulterLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_saveChangesLE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_voter_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshTreeView_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshStat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshStat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supListe_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourAJ_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourAff_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourModif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourVote_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourStats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourSupp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
