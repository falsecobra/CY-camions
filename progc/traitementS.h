#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <string.h> //pour comparer les noms de villes

// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement


typedef struct avl {
  unsigned long int val;
  float distancemax;
  float distancemin;
  float distancemoy;
  float dif;
  int nboccu;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl;


void triFusion(int i, int j, avl* tab[50], avl* tmp[50]);

void colonnemauvais (int n,char colonne[100],char ligne[300]);

void indiceminpt(avl* liste[50],float*m);

void remplacept (avl* liste[50],avl* a,float *m);

void colonnecutul(int n,unsigned long int* pt,char ligne[300]);

void colonnecutf(int n,float* pt,char ligne[300]);

int min(int liste[]);

avl *creerarbre(unsigned long int nb,float d);

avl *RotationGauche(avl *a);

avl *RotationDroite(avl *a);

avl *DoubleRotationGauche(avl *a);

avl *DoubleRotationDroite(avl *a);

void afficherinf(avl *a);

avl *equilibrer(avl *a);

int recherche(avl *a, unsigned long int nb);

avl *insertion(avl *a, unsigned long int nb, int *h,avl*liste[50],float distance,float* m);

void affichept(avl* liste[50],FILE * fichier);

void dynamiter(avl* arbre);

