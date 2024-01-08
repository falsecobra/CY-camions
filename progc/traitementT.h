#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> //pour comparer les noms de villes

// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement

typedef struct avl {
  int val;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl;

int min(int liste[]) {
}

int max(int liste[]) {
  
}

avl *creerarbre(int nb) {
  
}

avl *RotationGauche(avl *a) {
 
}

avl *RotationDroite(avl *a) {
  
}

avl *DoubleRotationGauche(avl *a) {
  a->fd = RotationDroite(a->fd);
  a = RotationGauche(a);
  return a;
}

avl *DoubleRotationDroite(avl *a) {
  
}

void afficher(avl *a) {
  
}
void afficherinf(avl *a) {
  
}

avl *equilibrer(avl *a) {
  
}

avl *insertion(avl *a, int nb, int *h) {
  
    
}

