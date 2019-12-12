#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"vol.h"
#include "reservervol.h"
#include <gtk/gtk.h> 


enum
{	
	Identif,
	Idres,
	Idvol,
	DEPART,
	DESTINATION,
	JOURDepart,
	MOISDepart,
	ANNEEDepart,
	JOURArriver,	
	MOISArriver,
	ANNEEArriver,
	Personne,
	Montant,
        COLUMNS
};


void ajouter_reservationvol(Volr r)
{
FILE*f=NULL;
FILE*f2=NULL;
FILE*f1=NULL;
int dateDEPARTjour,dateDEPARTmois,dateDEPARTannee,dateARIVEEjour,dateARIVEEmois,dateARIVEEannee,prix;
char id_vol[10],depart[10],destination[10],companie[10];
int montant,b;
vol v;
f=fopen("reservervol.txt","a+");
f2=fopen("vol.txt","r");
 
b=r.personne;
while(fscanf(f2,"%s %s %s %s %d %d %d %d %d %d %d\n",id_vol,depart,destination,companie,&dateDEPARTjour,&dateDEPARTmois,&dateDEPARTannee,&dateARIVEEjour,&dateARIVEEmois,&dateARIVEEannee,&prix)!=EOF)
{ 
        if(strcmp(id_vol,r.id_vol)==0)
        {
             fprintf(f,"%s %s %s %d %d %d %d %d %d %s %s %d %d\n",r.identifiant,r.id_reservation,r.id_vol,r.depart.jour,r.depart.mois,r.depart.annee,r.arrivee.jour,r.arrivee.mois,r.arrivee.annee,depart,destination,r.personne,prix*b);
  
          }

}
fclose(f);

fclose(f2);


}


int chercher_reservoldisp(Volr r)
{
int x=1;
FILE*f2=NULL;

int b=0;

vol v;

f2=fopen("vol.txt","r");
	


while(fscanf(f2,"%s %s %s %s %d %d %d %d %d %d %s \n",v.id_vol,v.depart,v.destination,v.companie,&(v.date_depart->jour),&(v.date_depart->mois),&(v.date_depart->annee),&(v.date_arrivee->jour),&(v.date_arrivee->mois),&(v.date_arrivee->annee),(v.prix))!=EOF)
{
        if((strcmp(v.id_vol,r.id_vol)==0) && (strcmp(v.destination,r.vdestination)==0) )
        
            { x=1;
      	
           break;}
	else if((strcmp(v.id_vol,r.id_vol)!=0) && (strcmp(v.destination,r.vdestination)!=0) )
	{ x=0;
      	
           break;}
}



fclose(f2);
return x;

}

void afficher_reservationvol(GtkWidget *liste)
{
   GtkCellRenderer *renderer; 

   GtkTreeViewColumn *column;

   GtkTreeIter iter;

   GtkListStore *store;

	char identif[30];
	char idres[30];
	char idvol[30];
	char depart[30];
	char destination[30];
	char jourDepart[30];
	char moisDepart[30];
	char anneeDepart[30];
	char jourArriver[30];	
	char moisArriver[30];
	char anneeArriver[30];
	char personne[30];
	char montant[30];
	store=NULL;

   FILE *f;
   store = gtk_tree_view_get_model(liste);
   if (store==NULL)

 

 renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" identif", renderer, "text",Identif, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" idres", renderer, "text",Idres, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

      renderer = gtk_cell_renderer_text_new ();  
      column = gtk_tree_view_column_new_with_attributes(" idvol", renderer, "text",Idvol, NULL); 
      gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" jourDepart", renderer, "text",JOURDepart, NULL); 
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
column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" destination", renderer, "text",DESTINATION, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" personne", renderer, "text",Personne, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" montant", renderer, "text",Montant, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  f = fopen("reservervol.txt", "r"); 

  if(f==NULL)
  {
    return;
  }
  else

  { f = fopen("reservervol.txt", "a+");

       while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s ",identif,idres,idvol,jourDepart,moisDepart,anneeDepart,jourArriver,moisArriver,anneeArriver,depart,destination,personne,montant)!= EOF))
    {
  gtk_list_store_append (store, &iter);

  gtk_list_store_set (store, &iter,Identif,identif,Idres,idres,Idvol,idvol,JOURDepart,jourDepart,MOISDepart,moisDepart,ANNEEDepart,anneeDepart, JOURArriver,jourArriver,MOISArriver,moisArriver,ANNEEArriver,anneeArriver,DEPART,depart,DESTINATION,destination,Personne,personne, Montant,montant, -1);
    }
    fclose(f);
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
}


void supprimer_volres(char identif[])
{int b=0;
FILE*f=NULL;
FILE*f1=NULL;
Volr r;
f=fopen("reservervol.txt","r");
f1=fopen("tmp.txt","w");


while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s %s %d %d\n",r.identifiant,r.id_reservation,r.id_vol,&r.depart.jour,&r.depart.mois,&r.depart.annee,&r.arrivee.jour,&r.arrivee.mois,&r.arrivee.annee,r.vdepart,r.vdestination,&r.personne,&r.montant)!=EOF)
{
        if((strcmp(r.identifiant,identif)!=0))
        {
        fprintf(f1,"%s %s %s %d %d %d %d %d %d %s %s %d %d\n",r.identifiant,r.id_reservation,r.id_vol,r.depart.jour,r.depart.mois,r.depart.annee,r.arrivee.jour,r.arrivee.mois,r.arrivee.annee,r.vdepart,r.vdestination,r.personne,r.montant);
b=1;
}

}

fclose(f);
fclose(f1);
remove("reservervol.txt");
rename("tmp.txt","reservervol.txt");

 }



			

int tableau_resvol_disponible(char tab[50][10])
{
	int i,nS=0;
	FILE* f=fopen("reservervol.txt","r");
	Volr r;
	
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %d %d %d %d %d %d %s %s %d %d\n",r.identifiant,r.id_reservation,r.id_vol,&r.depart.jour,&r.depart.mois,&r.depart.annee,&r.arrivee.jour,&r.arrivee.mois,&r.arrivee.annee,r.vdepart,r.vdestination,&r.personne,&r.montant)!=EOF)
		{
			
					
						strcpy(tab[nS],r.identifiant);
						nS++;
					}
					
	}
	fclose(f);
	return nS;
}



void affichemontant(char mont[])
{
char s1[10],s2[10],s3[10],s4[10],s5[10],s6[10],s7[10],s8[10],s9[10],s10[10],s11[10],s12[10],s13[10];
FILE* f=fopen("reservervol.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13)!=EOF)
{
strcpy(mont,s13);
}
fclose(f);}



void affichedepartdestination(char depart[],char destin[],char idv[10])
{
char s1[10],s2[10],s3[10],s4[10],s5[10],s6[10],s7[10],s8[10],s9[10],s10[10],s11[10],s12[10],s13[10];
FILE* f1=fopen("reservervol.txt","r");
FILE* f=fopen("vol.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13)!=EOF)
{ 
if(strcmp(s1,idv)==0)
{
strcpy(depart,s2);
strcpy(destin,s3);
}
}
fclose(f);
fclose(f1);
}

void ajouter_reservationvolclient(Volr r)
{
FILE*f=NULL;
FILE*f2=NULL;
FILE*f1=NULL;
int dateDEPARTjour,dateDEPARTmois,dateDEPARTannee,dateARIVEEjour,dateARIVEEmois,dateARIVEEannee,prix;
char id_vol[10],depart[10],destination[10],companie[10],s1[10],idclient[10];
int montant,b;
vol v;
f=fopen("reservervol.txt","a+");
f2=fopen("vol.txt","r");
f1=fopen("client.txt","r");
 
b=r.personne;

while(fscanf(f1,"%s\n",s1)!=EOF)
{
strcpy(idclient,s1);
}

while(fscanf(f2,"%s %s %s %s %d %d %d %d %d %d %d\n",id_vol,depart,destination,companie,&dateDEPARTjour,&dateDEPARTmois,&dateDEPARTannee,&dateARIVEEjour,&dateARIVEEmois,&dateARIVEEannee,&prix)!=EOF)
{ 
        if(strcmp(id_vol,r.id_vol)==0)
        {
             fprintf(f,"%s %s %s %d %d %d %d %d %d %s %s %d %d\n",idclient,r.id_reservation,r.id_vol,r.depart.jour,r.depart.mois,r.depart.annee,r.arrivee.jour,r.arrivee.mois,r.arrivee.annee,depart,destination,r.personne,prix*b);
  
          }
}
fclose(f);

fclose(f2);
fclose(f2);
}


