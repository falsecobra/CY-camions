// globablement un casi recopiage de traitementS
#include "traitementL.h"

/* ALGORITHME assez similaire au traitementS On trie tout d'abord  via avl par numero de trajet avecl'attribut distance qui sera incrémenté à chaque insertion

on etablit une liste de 10 pointeurs vers les elements dotés des plus grandes valeurs distances */




// une fonction tri fusion trouvée sur internet modifiée pour fonctionner avec des flottants elle servira pour la liste de pointeurs

void triFusion(int i, int j, avl* tab[10], avl* tmp[10]) {//tab  estcelui a trier
    if(j <= i){ return;}

    int m = (i + j) / 2;

    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg]->val > tab[pd]->val) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}

void colonnemauvais (int n,char colonne[100],char ligne[300])//équivalent de la commande cut mais en c, n represente le numero de la colonne 0 est la 1ere colonne
{
  for (int i =0;i<100;i++){//vide "colonne"
      colonne[i]='\0';
  }
  int comptevirgule=0,debcolonne =0;
  for (int i =0;i<300;i++){
    if (comptevirgule==n){ 

        if ((ligne[i]!=';')&&(ligne[i]!='\0')){
           colonne[i-debcolonne]=ligne[i];

      }
      else{return;}
    }

    if (ligne[i]==';'){
      comptevirgule+=1;
      debcolonne=i+1;
    }


  }
  return;
}

void indiceminpt(avl* liste[10],long double*m){//met la valeur de dif du pt avec l'attribut dif le plus bas dans m
  // IMPORTANT NE PAS UTILISER AVEC UNE LISTE PARTIELLEMENT REMPLIE
  //if (liste[0]!=NULL){
  *m = liste[0]->distance;
  for (int i = 1; i < 10; i++) {


    if (liste[i]->distance < *m) {
      *m = liste[i]->distance;
    }
  }  
}

void remplacept (avl* liste[10],avl* a,long double *m){//remplace le trajet ayant la valeur minimale de différences parmis la liste de pointeurs par le trajet passé en paramètre 
  //APPELER CETTE FONCVTION SSI A->dif >*m

  if (*m<0){//liste pas pleinement remplie
  for (int i =0; i<10;i++){

    if  (liste[i]==NULL){//cas de début ou il n'y a pas encore assez de trajet
      if (liste[i]==a){//le trajet est deja dans la liste
        return;
      }
      liste[i]=a;
    if (i==9){// la liste va se remplir :)
      indiceminpt(liste,m);
    }


    return;
  }

  }}
  else {
    for (int i =0; i<10;i++){// la liste est deja remplie
  if (liste[i]==a){//le trajet est deja dans la liste
    indiceminpt(liste,m);
    return;
  }}
  for (int i =0; i<10;i++){
  if (liste[i]->distance==*m){// on trouve l'abscisse du minimum
    liste[i]=a;
    indiceminpt(liste,m);
    return;}}}}

void colonnecutul(int n,unsigned long int* pt,char ligne[300]){//comme colonnemauvais mais pour les entiers long
  unsigned long int essai;

  char colonnet[100];
  colonnemauvais(n,colonnet,ligne);
  

  char* end;
 essai= strtoul(colonnet, &end, 0);
  if(end==colonnet){

    printf("champ invalide fonction colonnecutul");

    exit (5);
  }
  *pt=essai;

}

void colonnecutf(int n,long double * pt,char ligne[300]){//comme colonnecutul mais pour les reels
  long double  essai;
  char colonnet[100];
  colonnemauvais(n,colonnet,ligne);
  char* end;
 essai= strtof(colonnet, &end);
  if(end==colonnet){
    printf("champ invalide fonction colonnecutf");
    exit (7);
  }
  *pt=essai;

}



 //les fonctions avl du td un peu modifiées :
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

avl *creerarbre(unsigned long int nb,long double d) {
  avl *noeud = malloc(sizeof(avl));
  noeud->val = nb;
  noeud->distance=d;
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


void afficherinf(avl *a) {
  if (a == NULL) {
    return;
  }
  afficherinf(a->fg);
  printf("trajet %lu, distance %Lf", a->val,a->distance);
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

int recherche(avl *a, unsigned long int nb) { // renvoie 1 si nb existe dans l'avl ,0sinon
  if (a->val == nb) {
    return 1;
  } else if (a->val < nb) {
    if (a->fd == NULL) {
      return 0;
    } else {
      return recherche(a->fd, nb);
    }
  } else {
    if (a->fg == NULL) {
      return 0;
    } else {
      return recherche(a, nb);
    }
  }
}

avl *insertion(avl *a, unsigned long int nb, int *h,avl*liste[50],long double distancin,long double * m) {
  if (a == NULL) {
    *h = 1;
    avl * apr=creerarbre(nb,distancin);
    if (apr->distance>*m){
      remplacept(liste,apr,m);
    }
    return apr;
  } else if (a->val == nb) {//le trajet est d'ores et déjà dans l'arbre
    a->distance=(a->distance)+(distancin);//actualise la distance
    
    if (a->distance>*m){
      remplacept(liste,a,m);
    }

    *h = 0;
    return a;
  } else if (a->val > nb) {
    a->fg = insertion(a->fg, nb, h,liste,distancin,m);
    *h = -*h;
  }

  else if (a->val < nb) {

    a->fd = insertion(a->fd, nb, h,liste,distancin,m);
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

void affichept(avl* liste[10],FILE* fichier){//fonction d'aide spectatrice
  for (int i=0; i<10; i++){
    if (liste[i]!=NULL){
    fprintf(fichier,"%lu;%Lf\n",liste[i]->val,liste[i]->distance);}
  }     
}

void dynamiter(avl* arbre){
  if (arbre==NULL){
    return;
  }
  avl* copied = arbre->fd;
  avl* copieg = arbre->fg;
  free(arbre);
  dynamiter(copied);
  dynamiter(copieg);
  return;
  
}








int main(int argc, char *argv[]){
  int hpt=0;
  unsigned long int lupt=0;
  long double fpt=0;
  long double minima = -1.0;//vaudra une valeur postive quand la liste sera remplie
  avl* trouve=NULL;// recherche
  long double* m = &minima;  //pour la liste des pointeurs
  int* h = &hpt;  //pour l'insertion
  avl* listept[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//liste des pointeurs

  avl* listept2[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//liste des pointeurs2 pr tri



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
  modif= fopen(argv[2],"w+");
  if (modif==NULL){
    printf("fichier 2 invalide !");
      exit(3);
  }



  time_t debut, fin; 
  time(&debut);//démarre le chrono
  avl* av= creerarbre(0,0.0);


  char ligne[300];
  if(fgets(ligne, 300, data)!=NULL){}//on ignore la 1ere ligne
  else {
    printf("erreur lecture fichier");
      exit(6);
  }
unsigned long int cligne =1;

  while (fgets(ligne, 300, data)!=NULL){//parcours tout le fichier
    cligne+=1;
    if (strlen(ligne)>10){//comparaison arbitraire qui evite un bug
      lupt=0;
      fpt=0;
    colonnecutul (0,&lupt,ligne);//ne prend que le numero de trajet
    colonnecutf (4,&fpt,ligne);//prend la distance



    av= insertion(av,lupt,h,listept,fpt,m);//on ajoute tout la fonction modifie toutes les valeurs comme il faut
    }
}


 

  //affichept(listept2,modif);
  triFusion (0,9,listept,listept2);

  affichept(listept,modif);

  
dynamiter(av);
  
  
 

fclose(data);
fclose(modif);

  time (&fin);//éteint le chrono
    printf("\nTraitement L effectué en %f secondes !\n",difftime(fin,debut));
  return 0;
}
