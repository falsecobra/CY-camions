#include "traitementD1.h"


/*ce traitement indique les 10 conducteurs ayant effectué le plus de trajets.


Algorithme:

1) On parcours le fichier data et pour chaque ligne où step_id =1 
on la copie dans le fichier du tri.
A la fin, le dit fichier ne contiendra qu'une ligne par trajet, ce-faisant il sera plus léger et plus aisément manipulable. 

2) On déclare un AVL à partir du fichier du tri où les noeuds sont une structure dont la construction est:
noeud {
-str nom (nom du conducteur, on suppose qu'il n'y a pas de chauffeurs distincts mais homonymes)
-int nbtrajets (vaut 1 au début)
-noeud* fg
-noeud* fd
-entier equi}
Les fonctions de manipulations de l'avl seront celles du td modifiées
par exemple pour dans le cas ou le conducteur existe deja on augmentera la valeur de 
nbtrajets

3) Remplissage de l'avl en gardant une liste de 10 pointeurs vers noeud qui conserveront les 10 conducteurs au plus de trajets , cette liste sera modifiée au fil du remplissage.

4) On réinitialise le fichier tri, pour ensuite y mettre le nom des 10 conducteurs qui ont fait le plus de trajets différents à partir de la liste susmentionnée, dans le bon ordre.


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