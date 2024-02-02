#include "traitementT.h"


/*ce traitement indique les 10 villes ayant effectué les plus visitées.

Algorithme:
Premier tri  par nombres croissants de trajets 
Dans un avl qui contient
 nb trajets
 villa (ajoutée ssi step id ==0) 
Un avl de villeb 

On n'ajoute pas si villea =villeb
Sauf si stepid=0? (Demander à nico si l'actuel donne le bon nombres de départ) 
Si ville b pas dans le sous avl des trajets alors on l'ajoute dans le sous avl mais aussi dans l'avl ville (cas du doublon dans l'insertion > ne fait rien) 

Simultanément on a un avl de villes (l'actuel) 
Qui sera actualisé au fur et à mesure de l'insertion dans l'avl des trajets






On déclare un AVL à partir du fichier du tri où les noeuds sont une structure dont la construction est:
noeud {
-str vil (nom de la ville)
-int nbvis (nb de visites)
-int nbdepart(nombre de depart de trajet depuis cette ville )
-noeud* fg
-noeud* fd
-entier equi}

On va initialiser une liste de 10 pointeurs vers noeuds qui seront dirigés vers 
les 10 villes dont l'attribut nboc est le plus élévé , cette liste sera actualisée au fil de l'insertion.

Remplissage de l'AVL par nom de ville triée selon l'ordre alphabétique ,pour le problème de doublons arrivée-départ d'étapes successives, on ne s'occupera que des villes d'arrivées sauf si le champ step_id vaut 1 (car la ville d'origine ne sera dans aucune case de ville d'arrivée )



on ecrit les 10 villes par ordre alphabétique dans le 2ème fichier en argument
on dynamite l'AVL 
*/



// j'ai copié puis collé ci dessous les méthodes du td avl en les modifiant adéquatement


/*typedef struct avl {
  char vil[45];//on aurait pu faire une liste chainée mais une chaine de caractère est plus simple ;
  int nbvis;
  struct avl *fg;
  struct avl *fd;
  int equi;
} avl; */





void colonnecut (int n,char colonne[45],char ligne[300])//équivalent de la commande cut mais en c, n represente le numero de la colonne 0 est la 1ere colonne
{
  for (int i =0;i<45;i++){//vide "colonne"
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


int min(int liste[]) {
  int maxi = liste[0];
  for (int i = 1; i < 20; i++) {
    if (liste[i] < maxi) {
      maxi = liste[i];
    }
  }
  return maxi;
}

void indiceminpt(avl* liste[10],int*m){//met la valeur de nbvis du pt avec l'attribut nbvis le plus bas dans m
  if (liste[0]!=NULL){
  *m = liste[0]->nbvis;
  for (int i = 1; i < 10; i++) {
    if (liste[i]!=NULL){

    if (liste[i]->nbvis < *m) {
      *m = liste[i]->nbvis;
    }}
  }  }
}

void remplacept (avl* liste[10],avl* a,int *m){//remplace la ville ayant la valeur minimale des nombres de visites parmis la liste de pointeurs par la ville passée en parametre 


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
  if (liste[i]->nbvis==*m){// on trouve l'abscisse du minimum
    liste[i]=a;
    indiceminpt(liste,m);
    return;}}}}
  /*ANCIENNE VERSION :
  for (int i =0; i<10;i++){
  if  (liste[i]==NULL){//cas de début ou il n'y a pas encore assez de villes
    liste[i]=a;
    indiceminpt(liste,m);
    return;
  }
  else if (liste[i]==a){// la ville est deja dans la liste
    return;
  }}

  if (a->nbvis>*m){//il doit y avoir un changement
    for (int i =0; i<10;i++){
      if (liste[i]->nbvis==*m){// on trouve l'abscisse du minimum
        liste[i]=a;
        indiceminpt(liste,m);
        return;
      }
      }
  }
}*/




int max(int liste[]) {
  int maxi = liste[0];
  for (int i = 1; i < 20; i++) {
    if (liste[i] > maxi) {
      maxi = liste[i];
    }
  }
  return maxi;
}

void tript(avl*liste[10]){//renvoie la liste triée par ordre alphabétique avec un algorithme très suboptimal mais pour 10 elements ça ira




  for (int i=0; i<10; i++){
    int copy=i;

    avl * va= liste[i];//fonctionne comme min temporaire
    for (int y=i; y<10; y++)
    {//on trouve la ville la plus avancée on la met en indice I


    if(strcmp (liste[y]->vil ,va->vil)<0){//liste y avant va
      va = liste[y];
      copy=y;
    }
    }
    avl*copie = liste[i];
    liste[i]=va;
    liste[copy]= copie;


  }

  /*for (int z=0; z<10;z++){
  strcpy(chmodif[z],liste[z]->vil);
  }*/



}

avl *creerarbre(char v[45]) {
  avl *noeud = malloc(sizeof(avl));
  strcpy (noeud->vil, v);
  noeud->nbvis = 1;
  noeud->nbdepart=0;
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
  printf("%s\n", a->vil);
  afficher(a->fg);
  afficher(a->fd);
  return;
}
void afficherinf(avl *a) {
  if (a == NULL) {
    return;
  }
  afficherinf(a->fg);
  printf("%s %d\n", a->vil,a->nbvis);
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

int recherche(avl *a, char v[45],avl**t) { // renvoie 1 si nb existe dans l'avl t vaudra l'arbre,0sinon 
  if (a==NULL){
    return 0;
  }
  if ( strcmp ( a->vil , v )==0) {
    *t=a;
    return 1;
  } else if (strcmp ( a->vil , v )<0) {
    if (a->fd == NULL) {
      return 0;
    } else {
      return recherche(a->fd, v,t);
    }
  } else {
    if (a->fg == NULL) {
      return 0;
    } else {
      return recherche(a->fg, v,t);
    }
  }
}


avl *insertion(avl *a, char v[45], int *h,avl*liste[10],int*m) {
  if (a == NULL) {
    *h = 1;
    avl * apr=creerarbre(v);
    if (apr->nbvis>*m){
      remplacept(liste,apr,m);
    }
    return apr;
  } else if ( strcmp ( a->vil , v )==0)  {//cas du doublon
    a->nbvis+=1;//la ville est visitée une fois de plus
    if (a->nbvis>*m){
      remplacept(liste,a,m);

    }

    *h = 0;
    return a;
  } else if (strcmp ( v , a->vil )<0) {//(a->val > nb) la ville à insérer est avant la ville du noeud
    a->fg = insertion(a->fg, v, h,liste,m);
    *h = -*h;
  }

  else if (strcmp ( v , a->vil )>0) {//(a->val > nb) la ville à insérer est après la ville du noeud

    a->fd = insertion(a->fd, v, h,liste,m);
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

void affichept(avl* liste[10],FILE*fichier){//fonction d'aide spectatrice
  for (int i=0; i<10; i++){
    if (liste[i]!=NULL){
    fprintf(fichier,"%s;%d;%d\n",liste[i]->vil,liste[i]->nbvis ,liste[i]->nbdepart);}
  }     
}

void affichestr(char liste[10][45]){//fonction d'aide spectatrice
  printf("\nListe des VIlles  :\n");
  for (int i=0; i<10; i++){
    if (liste[i]!=NULL){
    printf("%s \n",liste[i]);}
  }     
}





//fonctions sous avl
sousavl *creerarbres(char v[45]){
  sousavl *noeud = malloc(sizeof(sousavl));
  strcpy (noeud->vil, v);
  noeud->fg = NULL;
  noeud->fd = NULL;
  noeud->equi = 0;
  return noeud;
}

sousavl *RotationGauches(sousavl *a) {
  int eq_a, eq_p;
  sousavl *pivot = a->fd;
  sousavl *copie = a->fd->fg;
  a->fd = copie;
  pivot->fg = a;
  eq_a = a->equi;
  eq_p = pivot->equi;
  int listeq[20] = {0, eq_p};
  int listeqd[20] = {eq_a - 2, eq_p - 1, eq_a + eq_p - 2};
  a->equi = eq_a - max(listeq) - 1;
  pivot->equi = min(listeqd);
  return pivot;}

sousavl *RotationDroites(sousavl *a) {
  int eq_a, eq_p;
  sousavl *pivot = a->fg;
  sousavl *copie = pivot->fd;
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

sousavl *DoubleRotationGauches(sousavl *a) {
  a->fd = RotationDroites(a->fd);
  a = RotationGauches(a);
  return a;
}

sousavl *DoubleRotationDroites(sousavl *a)
{
  a->fg = RotationGauches(a->fg);
  a = RotationDroites(a);
  return a;
}

sousavl *equilibrers(sousavl *a){
  if (a->equi >= 2) {
    if (a->fd->equi < 0) {
      a = DoubleRotationGauches(a);
    } else {
      a = RotationGauches(a);
    }
  } else if (a->equi <= -2) {
    if (a->fg->equi > 0) {
      a = DoubleRotationDroites(a);
    } else {
      a = RotationDroites(a);
    }
  }
  return a;
}

sousavl *insertions(sousavl *a, char v[45], int *h,int *existedeja) {
  if (a == NULL) {
    *h = 1;
    sousavl * apr=creerarbres(v);
    *existedeja=0;
    return apr;
  } else if ( strcmp ( a->vil , v )==0)  {//cas du doublon on ne fait rien
    *existedeja=1;
    *h = 0;
    return a;
  } else if (strcmp ( v , a->vil )<0) {//(a->val > nb) la ville à insérer est avant la ville du noeud
    a->fg = insertions(a->fg, v, h,existedeja);
    *h = -*h;
  }

  else if (strcmp ( v , a->vil )>0) {//(a->val > nb) la ville à insérer est après la ville du noeud

    a->fd = insertions(a->fd, v, h,existedeja);
  }
  if (*h != 0) {
    a->equi += *h;
    a = equilibrers(a);
    if (a->equi == 0) {
      *h = 0;

    } else {
      *h = 1;
    }
  }
  return a;
}

void dynamiters(sousavl* arbre){
  if (arbre==NULL){
    return;
  }
  sousavl* copied = arbre->fd;
  sousavl* copieg = arbre->fg;
  free(arbre);
  dynamiters(copied);
  dynamiters(copieg);
  return;

}

int recherches(sousavl *a, char v[45],sousavl**t) { // renvoie 1 si nb existe dans l'avl t vaudra l'arbre,0sinon 
  if (a==NULL){
    return 0;
  }
  if ( strcmp ( a->vil , v )==0) {
    *t=a;
    return 1;
  } else if (strcmp ( a->vil , v )<0) {
    if (a->fd == NULL) {
      return 0;
    } else {
      return recherches(a->fd, v,t);
    }
  } else {
    if (a->fg == NULL) {
      return 0;
    } else {
      return recherches(a->fg, v,t);
    }
  }
}



//fonctions grosavl
grosavl *creerarbreg(unsigned long int v){
  char chaine[45]={""};
  grosavl *noeud = malloc(sizeof(grosavl));
  noeud->val=v;
  strcpy (noeud->villea, chaine);
  noeud->savl=NULL;
  noeud->fg = NULL;
  noeud->fd = NULL;
  noeud->equi = 0;
  return noeud;
}

grosavl *RotationGaucheg(grosavl *a) {
  int eq_a, eq_p;
  grosavl *pivot = a->fd;
  grosavl *copie = a->fd->fg;
  a->fd = copie;
  pivot->fg = a;
  eq_a = a->equi;
  eq_p = pivot->equi;
  int listeq[20] = {0, eq_p};
  int listeqd[20] = {eq_a - 2, eq_p - 1, eq_a + eq_p - 2};
  a->equi = eq_a - max(listeq) - 1;
  pivot->equi = min(listeqd);
  return pivot;}

grosavl *RotationDroiteg(grosavl *a) {
  int eq_a, eq_p;
  grosavl *pivot = a->fg;
  grosavl *copie = pivot->fd;
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

grosavl *DoubleRotationGaucheg(grosavl *a) {
  a->fd = RotationDroiteg(a->fd);
  a = RotationGaucheg(a);
  return a;
}

grosavl *DoubleRotationDroiteg(grosavl *a)
{
  a->fg = RotationGaucheg(a->fg);
  a = RotationDroiteg(a);
  return a;
}

grosavl *equilibrerg(grosavl *a){
  if (a->equi >= 2) {
    if (a->fd->equi < 0) {
      a = DoubleRotationGaucheg(a);
    } else {
      a = RotationGaucheg(a);
    }
  } else if (a->equi <= -2) {
    if (a->fg->equi > 0) {
      a = DoubleRotationDroiteg(a);
    } else {
      a = RotationDroiteg(a);
    }
  }
  return a;
}

grosavl *insertiong(grosavl *a, unsigned long int v, int *h,int *existedeja,grosavl** ret) {
  if (a == NULL) {//il n'y a aucun noeux avec ce nom de trajet
    *h = 1;
    grosavl * apr=creerarbreg(v);
    *existedeja=0;
    *ret = apr;
    return apr;
  } else if (a->val==v)  {//cas du doublon on ne fait rien pr l'instant
    *existedeja=1;
    *h = 0;
    *ret = a;
    return a;
  } else if ( a->val>v) {//(a->val > nb) la ville à insérer est avant la ville du noeud
    a->fg = insertiong(a->fg, v, h,existedeja,ret);
    *h = -*h;
  }

  else if ( a->val<v) {//(a->val > nb) la ville à insérer est après la ville du noeud

    a->fd = insertiong(a->fd, v, h,existedeja,ret);
  }
  if (*h != 0) {
    a->equi += *h;
    a = equilibrerg(a);
    if (a->equi == 0) {
      *h = 0;

    } else {
      *h = 1;
    }
  }
  return a;
}

void dynamiterg(grosavl* arbre){
  if (arbre==NULL){
    return;
  }
  grosavl* copied = arbre->fd;
  grosavl* copieg = arbre->fg;
  sousavl* cavl =arbre->savl;
  free(arbre);
  dynamiterg(copied);
  dynamiterg(copieg);
  dynamiters(cavl);
  return;

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







int main(int argc, char *argv[]){

  int hpt=0;
  int minima = -1;
  avl* trouve=NULL;// recherche
  sousavl* trouves=NULL;// recherches
  int* m = &minima;  //pour la liste des pointeurs
  int* h = &hpt;  //pour l'insertion
  avl* listept[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//liste de spointeurs
  unsigned long int lupt=0;


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
  char villeinit[45]={"KAAAAAAAAAAA"};
  avl* av= creerarbre(villeinit);
  grosavl* gav =creerarbreg(-1);


  char ligne[300];
  char stepid[45];//colonne n°1
  char villeb[45];//colonne 3
  char vila[45];//colonne 2
  if(fgets(ligne, 300, data)!=NULL){}//on ignore la 1ere ligne

  else {
    printf("erreur lecture fichier");
      exit(6);
  }

  while (fgets(ligne, 300, data)!=NULL){//parcours tout le fichier
    if (strlen(ligne)>10){//comparaison arbitraire qui evite un bug
      *h=0;
    colonnecutul (0,&lupt,ligne);//ne prend que le numero de trajet
    colonnecut (1,stepid,ligne);
    colonnecut (3,villeb,ligne);
    colonnecut (2,vila,ligne); 
    int existedejaA=0,existedejaB=0;
    grosavl *retour=gav;
    gav=insertiong(gav, lupt, h,&existedejaA,&retour);
     if ((stepid[0]=='1')&&(stepid[1]=='\0')) {//cas step id =1
         strcpy (retour->villea, vila);//dans le gros avl on met la ville 0 du trajet
       if(recherches(retour->savl, vila,&trouves)){//si la ville de depart a deja été parcourue dans le trajet on réduit son nombre d'occu dans l'arbre des villes car ce parcours là ne compte pas
          if (recherche(av, vila,&trouve)){//la ville existe ce qui devrait tjr etre le cas


            //actualiser m
            trouve->nbdepart +=1;
       }}
       else {//autre cas
         //retour->savl=insertions(retour->savl, vila, h,&existedejaB);
         if (recherche(av, vila,&trouve)){// la ville existe deja donc on augmente nb depart
             trouve->nbdepart+=1;
           trouve->nbvis+=1;  
           }
           else{
           av= insertion(av,vila,h,listept,m);//on ajoute  la ville puis on la retrouve : on met son nbdepart à 1 et nbvis à 0;
           if(recherche(av, vila,&trouve)){
             trouve->nbdepart=1;
             
         }

       }}}
    //else {//step id!=1 
      if((recherches(retour->savl, villeb,&trouves))|| (strcmp ( vila , villeb )==0)||(strcmp ( retour->villea , villeb )==0)){//si la villeb a deja été parcourue dans le trajet on ne fais rien ou si c'est une etape fantome ou si elle est le depart du trajet

    }
      else {//sinon on l'ajoute dans le grand avl et dans le savl

        retour->savl=insertions(retour->savl, villeb, h,&existedejaB);
        av = insertion(av,villeb,h,listept,m);
        //on ajoute toutes les villes de fin d'étape 



      }}}






    /*av= insertion(av,villeb,h,listept,m);//on ajoute toutes les villes de fin d'étape 


    if ((stepid[0]=='1')&&(stepid[1]=='\0')) {//cas step id =1

      if (recherche(av, villea,&trouve)){// la ville existe deja donc on augmente nb depart
        trouve->nbdepart+=1;
      }
      else{
      av= insertion(av,villea,h,listept,m);//on ajoute  la ville puis on la retrouve : on met son nbdepart à 1 et nbvis à 0;
      recherche(av, villea,&trouve);
        trouve->nbdepart=1;
        trouve->nbvis=0;
    }}
  }}*/








  tript(listept);

  affichept(listept,modif);
  /*printf("\nandy = %d\n\n",candy);
  printf("\nmar = %d\n\n",cmar);
  printf("\nste colombes = %d\n\n",cc);
  printf("\nlen = %d\n\n",clen);*/
  //printf("%d\n" ,comptandi);

  dynamiter(av);
  dynamiterg(gav);

  fclose(data);
  fclose(modif);

  time (&fin);//éteint le chrono
    printf("\nTraitement T effectué en %f secondes !\n",difftime(fin,debut));
  return 0;
}