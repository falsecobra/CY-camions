#include "traitementT.h"


/*ce traitement indique les 10 conducteurs ayant effectué le plus de trajets.


Algorithme:



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





void colonnecut (int n,char colonne[100],char ligne[300])//équivalent de la commande cut mais en c, n represente le numero de la colonne 0 est la 1ere colonne
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

int main(int argc, char *argv[]){
  int hpt=0;
  int minima = -1;
  avl* trouve=NULL;// recherche
  int* m = &minima;  //pour la liste des pointeurs
  int* h = &hpt;  //pour l'insertion
  avl* listept[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};//liste de spointeurs
  

  
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
  int candy=0;
  int cmar=0;
  int cc=0;
  int clen=0;
  
  char ligne[300];
  char stepid[100];//colonne n°1
  char villeb[100];//colonne 3
  char villea[100];//colonne 2
  if(fgets(ligne, 300, data)!=NULL){}//on ignore la 1ere ligne
  //printf("%s %s %s\n",ligne,stepid,av->vil);}
  //char andi[45]={"ANDILLY"};
  //int comptandi=0;
  else {
    printf("erreur lecture fichier");
      exit(6);
  }
  while (fgets(ligne, 300, data)!=NULL){//parcours tout le fichier
    colonnecut (1,stepid,ligne);
    colonnecut (3,villeb,ligne);
    //if( strcmp ( andi , villeb )==0){
      //comptandi+=1;
    //}
    colonnecut (2,villea,ligne); 
    if ( strcmp ( villea ,villeb )!=0){
    char andi[45] = {"ANDILLY"};
    if ( strcmp ( villea , andi )==0){
      candy+=1;
    }
    char mar[45] = {"MARSEILLE"};
    if ( strcmp ( villea , mar )==0){
      cmar+=1;
    }
    char marc[45] = {"STE COLOMBE"};
    if ( strcmp ( villea , marc )==0){
      if (strlen(villeb)!=strlen(marc)){
        clen+=1;
      }
      
      cc+=1;
    }
    av= insertion(av,villeb,h,listept,m);//on ajoute toutes les villes de fin d'étape 
    
    
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
  }}

  
  




  
  tript(listept);

  affichept(listept,modif);
  /*printf("\nandy = %d\n\n",candy);
  printf("\nmar = %d\n\n",cmar);
  printf("\nste colombes = %d\n\n",cc);
  printf("\nlen = %d\n\n",clen);*/
  //printf("%d\n" ,comptandi);

  dynamiter(av);

fclose(data);
fclose(modif);

  time (&fin);//éteint le chrono
    printf("\nTraitement T effectué en %f secondes !\n",difftime(fin,debut));
  return 0;
}
