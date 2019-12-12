#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"vol.h"
#include <gtk/gtk.h>

enum
{
	ID_VOL,
	DEPART,
	DESTINATION,
	JOURDepart,
	MOISDepart,
	ANNEEDepart,
	JOURArriver,	
	MOISArriver,
	ANNEEArriver,
	COMPAGNIE,
	PRIX,
        COLUMNS
};

void ajouter_vol(vol v)
{
FILE*f=NULL;
 f=fopen("/home/user16/employevolv1/src/vol.txt","a+");
 fprintf(f,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,v.date_depart->jour,v.date_depart->mois,v.date_depart->annee,v.date_arrivee->jour,v.date_arrivee->mois,v.date_arrivee->annee,v.prix);

fclose(f);

}


void afficher_vol(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

	char id_vol[30];
	char depart[30];
	char destination[30];
	char jourDepart[30];
	char moisDepart[30];
	char anneeDepart[30];
	char jourArriver[30];	
	char moisArriver[30];
	char anneeArriver[30];
	char companie[30];
	char prix[30];
	store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)


      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" id_vol", renderer, "text",ID_VOL, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" destination", renderer, "text",DESTINATION, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" jourDepart", renderer, "text",JOURDepart, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" companie", renderer, "text",COMPAGNIE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" moisDepart", renderer, "text",MOISDepart, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" anneeDepart", renderer, "text",ANNEEDepart, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" jourArriver", renderer, "text",JOURArriver, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" moisArriver", renderer, "text",MOISArriver, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" anneeArriver", renderer, "text",ANNEEArriver, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("/home/user16/employevolv1/src/vol.txt", "r"); 

  if(f==NULL)
  {
    return;
  }
  else

  { f = fopen("/home/user16/employevolv1/src/vol.txt", "a+");

       while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s ",id_vol,depart,destination,jourDepart,moisDepart,anneeDepart,jourArriver,moisArriver,anneeArriver,companie,prix)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter, ID_VOL, id_vol, DEPART, depart, DESTINATION, destination, COMPAGNIE, companie, JOURDepart, jourDepart, MOISDepart, moisDepart, ANNEEDepart, anneeDepart, JOURArriver, jourArriver, MOISArriver, moisArriver, ANNEEArriver, anneeArriver, PRIX, prix, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}

int chercher_vol(char idvol[])
{
FILE*f=NULL;
vol v;
f=fopen("/home/user16/employevolv1/src/vol.txt","r");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,&(v.date_depart->jour),&(v.date_depart->mois),&(v.date_depart->annee),&(v.date_arrivee->jour),&(v.date_arrivee->mois),&(v.date_arrivee->annee),v.prix)!=EOF){
        if((strcmp(v.id_vol,idvol)!=0))
{
        
return 0;
        }else

        {
           return 1;
       }
}
fclose(f);
}


int supprimer_vol(char idvol[])
{int b=0;
FILE*f=NULL;
FILE*f1=NULL;
vol v;
f=fopen("/home/user16/employevolv1/src/vol.txt","r");
f1=fopen("/home/user16/employevolv1/src/tmp.txt","w");


while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,&(v.date_depart->jour),&(v.date_depart->mois),&(v.date_depart->annee),&(v.date_arrivee->jour),&(v.date_arrivee->mois),&(v.date_arrivee->annee),v.prix)!=EOF){
        if((strcmp(v.id_vol,idvol)!=0))
        {
        fprintf(f1,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,v.date_depart->jour,v.date_depart->mois,v.date_depart->annee,v.date_arrivee->jour,v.date_arrivee->mois,v.date_arrivee->annee,v.prix);
b=1;
}

}

fclose(f);
fclose(f1);
remove("/home/user16/employevolv1/src/vol.txt");
rename("/home/user16/employevolv1/src/tmp.txt","/home/user16/employevolv1/src/vol.txt");

 }

int modifier_vol(vol *vo)
{
FILE *f=NULL,*f1=NULL;
vol v;
int a=0;
f=fopen("/home/user16/employevolv1/src/vol.txt" ,"r+");
 f1=fopen("/home/user16/employevolv1/src/tmp.txt","a+");
if (f!=NULL)
{while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,&(v.date_depart->jour),&(v.date_depart->mois),&(v.date_depart->annee),&(v.date_arrivee->jour),&(v.date_arrivee->mois),&(v.date_arrivee->annee),v.prix)!=EOF)
{if (strcmp(vo->id_vol,v.id_vol)!=0)
fprintf(f1,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,v.date_depart->jour,v.date_depart->mois,v.date_depart->annee,v.date_arrivee->jour,v.date_arrivee->mois,v.date_arrivee->annee,v.prix);
else if(strcmp(vo->id_vol,v.id_vol)==0)
{fprintf(f1,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,vo->depart,vo->destination,vo->companie,vo->date_depart->jour,vo->date_depart->mois,vo->date_depart->annee,vo->date_arrivee->jour,vo->date_arrivee->mois,vo->date_arrivee->annee,vo->prix);
a=1;}
}
fclose(f1);
fclose(f);
remove("/home/user16/employevolv1/src/vol.txt");
rename("/home/user16/employevolv1/src/tmp.txt","/home/user16/employevolv1/src/vol.txt");
return (a);
}
}


int remplir_combovol(vol tab[])
{
	int n=0;
	FILE* f=fopen("/home/user16/employevolv1/src/vol.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s ",tab[n].id_vol,tab[n].depart,tab[n].destination,tab[n].companie,&(tab[n].date_depart->jour),&(tab[n].date_depart->mois),&(tab[n].date_depart->annee),&(tab[n].date_arrivee->jour),&(tab[n].date_arrivee->mois),&(tab[n].date_arrivee->annee),tab[n].prix)!=EOF)
			{n++;}
		fclose(f);
	}
	return n;
}




