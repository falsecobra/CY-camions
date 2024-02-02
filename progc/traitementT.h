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



typedef struct sousavl {
  char vil[45];
  struct sousavl *fg;
  struct sousavl *fd;
  int equi;
} sousavl;

typedef struct grosavl {
  unsigned long int val;
//on verifie EN PREMIER STEP ID =0
  char villea[45];//villea ajouté ssi step id= 0 si elle existe deja en tant que villeb dans le sous  avl on va la chercher dans le grand avl et on réduit nbvis de 1
  sousavl* savl;//toutes les villes b du trajet pas de doublon y compirs avec villea  on ajoute pas si villea =villeb 
  struct grosavl *fg;
  struct grosavl *fd;
  int equi;
} grosavl;

void colonnecut (int n,char colonne[45],char ligne[300]);//équivalent de la commande cut mais en c

int min(int liste[]) ;

void indiceminpt(avl* liste[10],int*m);
void minpt (avl* liste[10],avl* a);
void tript(avl*liste[10]);

int max(int liste[]) ;


avl *creerarbre(char v[45]) ;

avl *RotationGauche(avl *a) ;

avl *RotationDroite(avl *a) ;

avl *DoubleRotationGauche(avl *a) ;

avl *DoubleRotationDroite(avl *a);
void afficher(avl *a) ;
void afficherinf(avl *a) ;

avl *equilibrer(avl *a) ;

avl *insertion(avl *a, char v[45], int *h,avl* liste[10],int*m) ;

void affichept(avl* liste[10],FILE* fichier);

void dynamiter(avl* arbre);

void affichestr(char liste[10][45]);




//fonctions sous avl
sousavl *creerarbres(char v[45]) ;

sousavl *RotationGauches(sousavl *a) ;

sousavl *RotationDroites(sousavl *a) ;

sousavl *DoubleRotationGauches(sousavl *a) ;

sousavl *DoubleRotationDroites(sousavl *a);

sousavl *equilibrers(sousavl *a) ;

sousavl *insertions(sousavl *a, char v[45], int *h,int *existedeja) ;

void dynamiters(sousavl* arbre);

int recherches(sousavl *a, char v[45],sousavl**t);


//fonctions gros avl
grosavl *creerarbreg(unsigned long int val) ;

grosavl *RotationGaucheg(grosavl *a) ;

grosavl *RotationDroiteg(grosavl *a) ;

grosavl *DoubleRotationGaucheg(grosavl *a) ;

grosavl *DoubleRotationDroiteg(grosavl *a);

grosavl *equilibrerg(grosavl *a) ;

grosavl *insertiong(grosavl *a, unsigned long int v, int *h,int *existedeja,grosavl** ret);

void dynamiterg(grosavl* arbre);

void colonnemauvais (int n,char colonne[100],char ligne[300]);//recupere id trajet

void colonnecutul(int n,unsigned long int* pt,char ligne[300]);


