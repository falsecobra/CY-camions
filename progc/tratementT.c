#include "traitementT.h"


/*ce traitement indique les 10 conducteurs ayant effectué le plus de trajets.


Algorithme:



On déclare un AVL à partir du fichier du tri où les noeuds sont une structure dont la construction est:
noeud {
-str vil (nom de la ville)
-int nbvis (nb de visites)
-noeud* fg
-noeud* fd
-entier equi}

On va initialiser une liste de 10 pointeurs vers noeuds qui seront dirigés vers 
les 10 villes dont l'attribut nboc est le plus élévé , cette liste sera actualisée au fil de l'insertion.

Remplissage de l'AVL par nom de ville triée selon l'ordre alphabétique ,pour le problème de doublons arrivée-départ d'étapes successives, on ne s'occupera que les villes d'arrivées sauf si le champ step_id vaut 1 (car la ville d'origine ne sera dans aucune case de ville d'arrivée )



on ecrit les 10 villes par ordre alphabétique dans le 2ème fichier en argument
on dynamite l'AVL 
*/



// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement


typedef struct avl {
  char vil[45];//on aurait pu faire une liste chainée mais une chaine de caractère est plus simple ;
  int nbvis;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl;

int min(int liste[]) {
  int maxi = liste[0];
  for (int i = 1; i < 20; i++) {
    if (liste[i] < maxi) {
      maxi = liste[i];
    }
  }
  return maxi;
}

int max(int liste[]) {
  int maxi = liste[0];
  for (int i = 1; i < 20; i++) {
    if (liste[i] > maxi) {
      maxi = liste[i];
    }
  }
  return maxi;
}

avl *creerarbre(int nb) {
  avl *noeud = malloc(sizeof(avl));
  noeud->val = nb;
  noeud->fg = NULL;
  noeud->fd = NULL;
  noeud->equi = 0;
  return noeud;
}

avl *RotationGauche(avl *a) {
  int eq_a, eq_p;
  avl *pivot = a->fd;
  avl *copie = a->fd->fg;
  a->fd = copie;
  pivot->fg = a;
  eq_a = a->equi;
  eq_p = pivot->equi;
  int listeq[20] = {0, eq_p};
  int listeqd[20] = {eq_a - 2, eq_p - 1, eq_a + eq_p - 2};
  a->equi = eq_a - max(listeq) - 1;
  pivot->equi = min(listeqd);
  return pivot;
}

avl *RotationDroite(avl *a) {
  int eq_a, eq_p;
  avl *pivot = a->fg;
  avl *copie = pivot->fd;
  a->fg = copie;
  pivot->fd = a;
  eq_a = a->equi;
  eq_p = pivot->equi;
  int listeq[20] = {0, eq_p};
  int listeqd[20] = {eq_a + 2, eq_p + 1, eq_a + eq_p + 2};
  a->equi = eq_a - min(listeq) + 1;
  pivot->equi = max(listeqd);
  return pivot;
}

avl *DoubleRotationGauche(avl *a) {
  a->fd = RotationDroite(a->fd);
  a = RotationGauche(a);
  return a;
}

avl *DoubleRotationDroite(avl *a) {
  a->fg = RotationGauche(a->fg);
  a = RotationDroite(a);
  return a;
}

void afficher(avl *a) {
  if (a == NULL) {
    return;
  }
  printf("%d\n", a->val);
  afficher(a->fg);
  afficher(a->fd);
  return;
}
void afficherinf(avl *a) {
  if (a == NULL) {
    return;
  }
  afficherinf(a->fg);
  printf("%d\n", a->val);
  afficherinf(a->fd);
  return;
}

avl *equilibrer(avl *a) {
  if (a->equi >= 2) {
    if (a->fd->equi < 0) {
      a = DoubleRotationGauche(a);
    } else {
      a = RotationGauche(a);
    }
  } else if (a->equi <= -2) {
    if (a->fg->equi > 0) {
      a = DoubleRotationDroite(a);
    } else {
      a = RotationDroite(a);
    }
  }
  return a;
}

avl *insertion(avl *a, int nb, int *h) {
  if (a == NULL) {
    *h = 1;
    return creerarbre(nb);
  } else if (a->val == nb) {
    *h = 0;
    return a;
  } else if (a->val > nb) {
    a->fg = insertion(a->fg, nb, h);
    *h = -*h;
  }

  else if (a->val < nb) {

    a->fd = insertion(a->fd, nb, h);
  }
  if (*h != 0) {
    a->equi += *h;
    a = equilibrer(a);
    if (a->equi == 0) {
      *h = 0;

    } else {
      *h = 1;
    }
  }
  return a;
}


int main(int argc, char *argv[]){
  

  
  //verification d'arguments le premier argument est le fichier data le deuexieme un fichier qui sera une copie de data mais trié
  if (argc !=3){
    printf("Il faut deux arguments  ! \nLe premier argument est le fichier data le deuexieme un fichier qui sera une copie de data mais trié");//verifie le nombre d'argument
    exit(1);
  }
  FILE * data =NULL;
  data= fopen(argv[1],"r");
  if (data==NULL){
    printf("fichier 1 invalide !");
      exit(2);
  }
  FILE * modif =NULL;
  data= fopen(argv[2],"w+");
  if (data==NULL){
    printf("fichier 2 invalide !");
      exit(3);
  }


  time_t debut, fin; 
  time(&debut);//démarre le chrono

  
  char chaine[100];
  if(fgets(chaine, 100, data)!=NULL){//affiche la 1ere ligne
  printf("%s",chaine);}

  time (&fin);//éteint le chrono
    printf("\nTraitement D1 effectué en %f secondes !\n",difftime(fin,debut));
  return 0;
}