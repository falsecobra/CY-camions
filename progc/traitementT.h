#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <string.h> //pour comparer les noms de villes

// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement

typedef struct avl {
  char vil[45];
  int nbvis;
  int nbdepart;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl;

void colonnecut (int n,char colonne[100],char ligne[300]);//équivalent de la commande cut mais en c

int min(int liste[]) ;

void affichestr(char liste[10][45]);

void indiceminpt(avl* liste[10],int*m);
void remplacept (avl* liste[10],avl* a,int*m);
void tript(avl*liste[10],char chmodif[10][45]);

int max(int liste[]) ;


avl *creerarbre(char v[45]) ;

avl *RotationGauche(avl *a) ;

avl *RotationDroite(avl *a) ;

avl *DoubleRotationGauche(avl *a) ;

avl *DoubleRotationDroite(avl *a);
void afficher(avl *a) ;
void afficherinf(avl *a) ;

avl *equilibrer(avl *a) ;

int recherche(avl *a, char v[45],avl **t);

avl *insertion(avl *a, char v[45], int *h,avl* liste[10],int*m) ;



void affichept(avl* liste[10]);

