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

on ecrit les 10 villes par ordre alphabétique dans le fichier trié 
*/




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