#include <gtk/gtk.h> 

typedef struct date date;
struct date{
int jour;
int mois;
int annee;
};
typedef struct vol vol;
typedef struct vol{
char id_vol[30];
char depart[30];
char destination[30];
char companie[30];
date date_depart[30];
date date_arrivee[30];
char prix[30];
};

void ajouter_vol();
void afficher_vol(GtkWidget *liste);
int supprimer_vol(char idvol[10]);
int chercher_vol(char idvol[10]);
int modifier_vol(vol *vo);
int remplir_combovol(vol tab[50]);
int tableau_salle_disponible(char tab[50][10]);








