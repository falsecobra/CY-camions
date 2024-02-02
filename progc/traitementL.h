// j'ai globalement recopié le traitement S que j'avais fait avant 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <string.h> //pour comparer les noms de villes

// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement


typedef struct avl {
  unsigned long int val;
  long double distance;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl;


void triFusion(int i, int j, avl* tab[10], avl* tmp[10]);

void colonnemauvais (int n,char colonne[100],char ligne[300]);

void indiceminpt(avl* liste[10],long double *m);

void remplacept (avl* liste[10],avl* a,long double  *m);

void colonnecutul(int n,unsigned long int* pt,char ligne[300]);

void colonnecutf(int n,long double * pt,char ligne[300]);

int min(int liste[]);

avl *creerarbre(unsigned long int nb,long double  d);

avl *RotationGauche(avl *a);

avl *RotationDroite(avl *a);

avl *DoubleRotationGauche(avl *a);

avl *DoubleRotationDroite(avl *a);

void afficherinf(avl *a);

avl *equilibrer(avl *a);

int recherche(avl *a, unsigned long int nb);

avl *insertion(avl *a, unsigned long int nb, int *h,avl*liste[10],long double distancin,long double * m);

void affichept(avl* liste[10],FILE * fichier);

void dynamiter(avl* arbre);
