#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"
#include "reservervol.h"
#include<string.h>

void
on_gestionvols_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionvols;
GtkWidget *window1;
GtkWidget *treeview1;

window1=lookup_widget(objet,"window1");
gestionvols=create_gestionvols();
gtk_widget_destroy(window1);
gtk_widget_show(gestionvols);
treeview1=lookup_widget(gestionvols,"treeview1");
afficher_vol(treeview1);
}

void
on_retour_clicked                      (GtkWidget      *objet,
		                                gpointer         user_data)
{
GtkWidget *gestionvols;
GtkWidget *window1;

gestionvols=lookup_widget(objet,"gestionvols");
window1=create_window1();
gtk_widget_destroy(gestionvols);
gtk_widget_show(window1);


}
void
on_ajouter_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *ajoutervol;
GtkWidget *gestionvols;

gestionvols=lookup_widget(objet,"gestionvols");
ajoutervol=create_ajoutervol();
gtk_widget_destroy(gestionvols);
gtk_widget_show(ajoutervol);


}

	void
	on_ajoute_av_clicked                   (GtkWidget      *objet,
		                                gpointer         user_data)
	{
vol v;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget *ajoutervol;
ajoutervol=lookup_widget(objet,"ajoutervol");                                                 
input1=lookup_widget(objet ,"entry1");
input2=lookup_widget(objet ,"entry2");
input3=lookup_widget(objet ,"entry3");
input4=lookup_widget(objet ,"spinbutton1");
input5=lookup_widget(objet ,"spinbutton2");
input6=lookup_widget(objet ,"spinbutton3");
input7=lookup_widget(objet ,"spinbutton4");
input8=lookup_widget(objet ,"spinbutton5");
input9=lookup_widget(objet ,"spinbutton6");
input10=lookup_widget(objet ,"entry4");
input11=lookup_widget(objet ,"entry5");


strcpy(v.id_vol,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(input3)));
v.date_depart->jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
v.date_depart->mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
v.date_depart->annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input6));
v.date_arrivee->jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
v.date_arrivee->mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
v.date_arrivee->annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));
strcpy(v.companie,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input11)));
ajouter_vol(v);
	}



	void
	on_retour1_clicked                       (GtkWidget      *objet,
		                                gpointer         user_data)
	{GtkWidget *ajoutervol;
	GtkWidget *gestionvols;
	GtkWidget *treeview1;


	ajoutervol=lookup_widget(objet,"ajoutervol");
	gestionvols=create_gestionvols();
	gtk_widget_destroy(ajoutervol);
	gtk_widget_show(gestionvols);
	treeview1=lookup_widget(gestionvols,"treeview1");
	afficher_vol(treeview1);
	}



		
void
on_modifier_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *modifiervol22;
GtkWidget *gestionvols,*Combobox3;
vol tab[50];
int n,i;

gestionvols=lookup_widget(objet,"gestionvols");
modifiervol22=create_modifiervol22();
gtk_widget_show(modifiervol22);
Combobox3=lookup_widget(modifiervol22, "combobox3");
n=remplir_combovol(tab);

for(i=0;i<n;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox3),_(tab[i].id_vol));

}

	void
	on_valider_modifier_clicked            (GtkWidget      *objet,
		                                gpointer         user_data)
	{/*GtkWidget *modifiervol;
	GtkWidget *modifiervol22;

	modifiervol=lookup_widget(objet,"modifiervol");
	modifiervol22=create_modifiervol22();
	gtk_widget_show(modifiervol22);

	*/}

void
on_ajouter_modifer_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{


GtkWidget *v01,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10,*Combobox3,*modifiervol22;
char idvol[10];
vol v1;

Combobox3=lookup_widget(objet, "combobox3");
v01=lookup_widget(objet ,"entry7");
v2=lookup_widget(objet ,"entry8");
v3=lookup_widget(objet ,"spinbutton7");
v4=lookup_widget(objet ,"spinbutton8");
v5=lookup_widget(objet ,"spinbutton9");
v6=lookup_widget(objet ,"spinbutton10");
v7=lookup_widget(objet ,"spinbutton11");
v8=lookup_widget(objet ,"spinbutton12");
v9=lookup_widget(objet ,"entry9");
v10=lookup_widget(objet ,"entry10");





strcpy(v1.id_vol,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
strcpy(v1.depart,gtk_entry_get_text(GTK_ENTRY(v01)));
strcpy(v1.destination,gtk_entry_get_text(GTK_ENTRY(v2)));
v1.date_depart->jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v3));
v1.date_depart->mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v4));
v1.date_depart->annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v5));
v1.date_arrivee->jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v6));
v1.date_arrivee->mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v7));
v1.date_arrivee->annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (v8));
strcpy(v1.companie,gtk_entry_get_text(GTK_ENTRY(v9)));
strcpy(v1.prix,gtk_entry_get_text(GTK_ENTRY(v10)));

modifier_vol (&v1);
}


void
on_retour2_clicked                     (GtkWidget     *objet,
		                                gpointer         user_data)
{
	GtkWidget *modifiervol22;

	modifiervol22=lookup_widget(objet,"modifiervol22");
	gtk_widget_destroy(modifiervol22);
	

}


void
on_supprimer_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *Combobox2;
GtkWidget *Supprimervol;
GtkWidget *gestionvols;
vol tab[50];
int n,i;


gestionvols=lookup_widget(objet,"gestionvols");
Supprimervol=create_Supprimervol();
gtk_widget_show(Supprimervol);
gtk_widget_destroy(gestionvols);
Combobox2=lookup_widget(Supprimervol, "combobox2");

n=remplir_combovol(tab);

for(i=0;i<n;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox2),_(tab[i].id_vol));



}


void
on_valider_supprimer_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Combobox2,*label25;
GtkWidget *Supprimervol;
char idvol[10];
GtkWidget *msg;
int x;
int i;
Combobox2=lookup_widget(objet, "combobox2");
msg=lookup_widget(objet,"label25");

strcpy(idvol,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
i=supprimer_vol(idvol);
if(i=1)
gtk_label_set_text(GTK_LABEL(msg),"Suppression Réussie !");
else
gtk_label_set_text(GTK_LABEL(msg),"vol deja supprimé!");
}



void
on_reserver_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver;
GtkWidget *window1;
GtkWidget *treeview2;

window1=lookup_widget(objet,"window1");
volreserver=create_volreserver();
gtk_widget_destroy(window1);
gtk_widget_show(volreserver);
treeview2=lookup_widget(volreserver,"treeview2");
afficher_reservationvol(treeview2);

}

void
on_retour00_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver,*treeview1;
GtkWidget *gestionvols;

volreserver=lookup_widget(objet,"volreserver");
gestionvols=create_gestionvols();
gtk_widget_destroy(volreserver);
gtk_widget_show(gestionvols);
treeview1=lookup_widget(gestionvols,"treeview1");
afficher_vol(treeview1);

}


void
on_ajouterr_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver;
GtkWidget *ajouterRVOL,*Combobox6;
int i,n;
vol tab[10];

volreserver=lookup_widget(objet,"volreserver");
ajouterRVOL=create_ajouterRVOL();
gtk_widget_destroy(volreserver);
gtk_widget_show(ajouterRVOL);
Combobox6=lookup_widget(ajouterRVOL, "combobox6");

n=remplir_combovol(tab);

for(i=0;i<n;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox6),_(tab[i].id_vol));

}


void
on_ajouterresvol_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
Volr r;
int x;
char mont[10];

GtkWidget *input1, *input2,*Combobox6,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11,*input12,*msg,*M;
GtkWidget *ajoutervol;
ajoutervol=lookup_widget(objet,"ajoutervol");                                                 
input1=lookup_widget(objet ,"entry11");
input2=lookup_widget(objet ,"entry12");
Combobox6=lookup_widget(objet, "combobox6");
input4=lookup_widget(objet ,"spinbutton13");
input5=lookup_widget(objet ,"spinbutton14");
input6=lookup_widget(objet ,"spinbutton15");
input7=lookup_widget(objet ,"spinbutton16");
input8=lookup_widget(objet ,"spinbutton17");
input9=lookup_widget(objet ,"spinbutton18");
/*input10=lookup_widget(objet ,"entry14");
input11=lookup_widget(objet ,"entry15");*/
input12=lookup_widget(objet ,"spinbutton19");
msg=lookup_widget(objet,"label37");
M=lookup_widget(objet,"label70");


strcpy(r.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.id_reservation,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.id_vol,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox6)));
r.depart.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
r.depart.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
r.depart.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input6));
r.arrivee.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
r.arrivee.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
r.arrivee.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));



r.personne=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input12));

ajouter_reservationvol(r);

if(x=1)
gtk_label_set_text(GTK_LABEL(msg),"reservation reussie :) ");


affichemontant(mont);
gtk_label_set_text(GTK_LABEL(M),mont);

}

void
on__selectidvol_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *output10,*output11,*Combobox6;
char depart[10],destin[10];
Volr r;
char idv[10];

Combobox6=lookup_widget(objet, "combobox6");
output10=lookup_widget(objet,"dep");
output11=lookup_widget(objet,"des");
strcpy(idv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox6)));
affichedepartdestination(depart,destin,idv);

gtk_label_set_text(GTK_LABEL(output10),depart);
gtk_label_set_text(GTK_LABEL(output11),destin);

}



void
on_retourr1_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
/**/

}


void
on_modifierr_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{

}

void
on_supprimerr_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Combobox5;
GtkWidget *supprimerres;
GtkWidget *volreserver;
char tab[50][10];
int n,i;


volreserver=lookup_widget(objet,"volreserver");
supprimerres=create_supprimerres();
gtk_widget_show(supprimerres);
gtk_widget_destroy(volreserver);
Combobox5=lookup_widget(supprimerres, "combobox5");

n=tableau_resvol_disponible(tab);

for(i=0;i<n;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox5),_(tab[i]));


}


void
on_valider_suppresvol_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{


}


void
on_retour01_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_reservationvolemp_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver;
GtkWidget *gestionvols;
GtkWidget *treeview2;

gestionvols=lookup_widget(objet,"gestionvols");
volreserver=create_volreserver();
gtk_widget_destroy(gestionvols);
gtk_widget_show(volreserver);
treeview2=lookup_widget(volreserver,"treeview2");
afficher_reservationvol(treeview2);

}


void
on_actualiservol_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_restoursupparr_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
}



void
on_ressuppvol_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Combobox5,*label060;
GtkWidget *Supprimervol;
char identif[10];
GtkWidget *msgr;
int i;
Combobox5=lookup_widget(objet, "combobox5");
msgr=lookup_widget(objet,"label060");

strcpy(identif,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox5)));
supprimer_volres(identif);

gtk_label_set_text(GTK_LABEL(msgr),"Suppression Réussie !");
}


void
on_suprvolllres_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerres;
GtkWidget *volreserver;
GtkWidget *treeview2;

supprimerres=lookup_widget(objet,"supprimerres");
volreserver=create_volreserver();
gtk_widget_destroy(supprimerres);
gtk_widget_show(volreserver);
treeview2=lookup_widget(volreserver,"treeview2");
afficher_reservationvol(treeview2);
}


void
on_rmv_clicked                         (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *modifiervol;
	GtkWidget *gestionvols;
	GtkWidget *treeview1;


	modifiervol=lookup_widget(objet,"modifiervol");
	gestionvols=create_gestionvols();
	gtk_widget_destroy(modifiervol);
	gtk_widget_show(gestionvols);
	treeview1=lookup_widget(gestionvols,"treeview1");
	afficher_vol(treeview1);
}


void
on_rsv_clicked                        (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *Supprimervol;
	GtkWidget *gestionvols;
	GtkWidget *treeview1;


	Supprimervol=lookup_widget(objet,"Supprimervol");
	gestionvols=create_gestionvols();
	gtk_widget_destroy(Supprimervol);
	gtk_widget_show(gestionvols);
	treeview1=lookup_widget(gestionvols,"treeview1");
	afficher_vol(treeview1);
}


void
on_retourrrar_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
/**/
}


void
on_retourravag_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver;
GtkWidget *gestionvols;
GtkWidget *treeview1;

volreserver=lookup_widget(objet,"volreserver");
gestionvols=create_gestionvols();
gtk_widget_destroy(volreserver);
gtk_widget_show(gestionvols);
treeview1=lookup_widget(gestionvols,"treeview1");
afficher_vol(treeview1);
}


void
on__retourajrr_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *volreserver;
GtkWidget *ajouterRVOL;
GtkWidget *treeview2;

ajouterRVOL=lookup_widget(objet,"ajouterRVOL");
volreserver=create_volreserver();
gtk_widget_destroy(ajouterRVOL);
gtk_widget_show(volreserver);
treeview2=lookup_widget(volreserver,"treeview2");
afficher_reservationvol(treeview2);
}




void
on_resclient_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *clientres,*output,*Combobox7;
GtkWidget *window1;
char getID[10],s1[10];
vol tab[10];
int i,n;

window1=lookup_widget(objet,"window1");
clientres=create_clientres();
gtk_widget_destroy(window1);
gtk_widget_show(clientres);

output=lookup_widget(clientres,"label608id");

Combobox7=lookup_widget(clientres, "combobox7");

n=remplir_combovol(tab);

for(i=0;i<n;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox7),_(tab[i].id_vol));




FILE* f=fopen("client.txt","r");
while(fscanf(f,"%s",s1)!=EOF)
{
strcpy(getID,s1);
}
gtk_label_set_text(GTK_LABEL(output),getID);

fclose(f);






}


void
on_ajoutresclient_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
Volr r;
int x;
char mont[10];

GtkWidget *input1, *input2,*Combobox7,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11,*input12,*input13,*msg,*Mo;
GtkWidget *clientres;
clientres=lookup_widget(objet,"clientres");                                                 

Combobox7=lookup_widget(objet, "combobox7");
input4=lookup_widget(objet ,"spinbutton27");
input5=lookup_widget(objet ,"spinbutton28");
input6=lookup_widget(objet ,"spinbutton29");
input7=lookup_widget(objet ,"spinbutton30");
input8=lookup_widget(objet ,"spinbutton31");
input9=lookup_widget(objet ,"spinbutton32");
input12=lookup_widget(objet ,"spinbutton33");
input13=lookup_widget(objet ,"entry22idres");

msg=lookup_widget(objet,"label604");
Mo=lookup_widget(objet,"labelmont");



strcpy(r.id_vol,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox7)));
strcpy(r.id_reservation,gtk_entry_get_text(GTK_ENTRY(input13)));
r.depart.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4));
r.depart.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input5));
r.depart.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input6));
r.arrivee.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
r.arrivee.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
r.arrivee.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));
r.personne=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input12));

ajouter_reservationvolclient(r);

gtk_label_set_text(GTK_LABEL(msg),"reservation reussie :) ");


affichemontant(mont);
gtk_label_set_text(GTK_LABEL(Mo),mont);
}


void
on_retourcv_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *clientres;
GtkWidget *window1;

clientres=lookup_widget(objet,"clientres");
window1=create_window1();
gtk_widget_destroy(clientres);
gtk_widget_show(window1);
}


void
on_depdestclient_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *output10,*output11,*Combobox7;
char depart[10],destin[10];
Volr r;
char idv[10];

Combobox7=lookup_widget(objet, "combobox7");
output10=lookup_widget(objet,"depp");
output11=lookup_widget(objet,"dess");
strcpy(idv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox7)));
affichedepartdestination(depart,destin,idv);

gtk_label_set_text(GTK_LABEL(output10),depart);
gtk_label_set_text(GTK_LABEL(output11),destin);

}

