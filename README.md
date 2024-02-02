#COMPILATION : 
#UTILISATION : 
---------------------------présentation---------------------------------
Ce programme est un outil qui permet d'analyser et de résumer les données donnée dans
un fichier volumineux. Ce fichier contient pleins de données concernant une société
nationale de transport routier.
---------------------------utilisation----------------------------------
une fois dans le fichier où se trouve le programme, afin de l'executer il va falloir l'appeler de la forme :

bash scriptShell.sh [cheminvers/fichier .csv] [traitement]

attention, programme ne prends pas plus d'un traitement.
les différents traitements : 
  -d1 : conducteurs avec le plus de trajet
  -d2 : conducteurs avec la plus grande distance parcouru ( au total )
  -l : les dix trajets les plus long
  -t : les dix villes les plus traversées
  -s statistique sur les étapes

A la fin du traitement, le programme vous ouvrira un graphique résumant explicitement le traitement.
Vous pouvez toujours revoir ces images dans le dossier image/ que le programme va crée.
