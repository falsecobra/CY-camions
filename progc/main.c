#include "main.h"

// ici se trouverons les fonctions -s et -t
// Fonction qui permet de traiter les arguments de la ligne de commande
// et de les stocker dans des variables globales
void traitement_arguments(int argc, char** argv) {
  // On vérifie qu'argc est bien égal à 2
  if (argc != 2) {
    printf("Erreur : l'utilisateur doit fournir exactement un argument.\n");
    exit(1);
  }
  // On vérifie que le premier argument est bien -s
  if (strcmp(argv[1], "-s") != 0) {
    printf("Erreur : l'utilisateur doit fournir le premier argument '-' suivi de 's'.\n");
    exit(1);
  }
  // On vérifie que le deuxième argument est bien -t
  if (strcmp(argv[2], "-t") != 0) {
    printf("Erreur : l'utilisateur doit fournir le deuxième agrument '-' suivi de 't'.\n");
    exit(1);
  }
  // Si tout est correct, on stocke les arguments dans les variables globales
  // s_option et t_option
  s_option = 1;
  t_option = 1;
}

// Fonction qui permet de traiter les arguments de la ligne de commande
// et de les stocker dans des variables globales
void traitement_arguments_2(int argc, char** argv) {
  // On vérifie qu'argc est bien égal à 2
  if (argc != 2) {
    printf("Erreur : l'utilisateur doit fournir exactement un argument.\n");
    exit(1);
  }
  // On vérifie que le premier argument est bien -s
  if (strcmp(argv[1], "-s") != 0) {
    printf("Erreur : l'utilisateur doit fournir le premier argument '-' suivi de 's'.\n");
    exit(1);
  }
  // On vérifie que le deuxième argument est bien -t
  if (strcmp(argv[2], "-t") != 0) {
    printf("Erreur : l'utilisateur doit fournir le deuxième agrument '-' suivi de 't'.\n");
    exit(1);
  }
  // Si tout est correct, on stocke les arguments dans les variables globales
  // s_option et t_option
  s_option = 0;
  t_option = 1;
}
// Fonction qui permet de traiter les arguments de la ligne de commande
// et de les stocker dans des variables globales

int main (){ // argument dans le main :  int main(int argc, char**argv)
  printf("test main\n");
  return 0;
}