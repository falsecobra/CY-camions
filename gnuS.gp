# Configuration du terminal de sortie (par exemple, PNG)
set terminal pngcairo size 1400,1000
set output 'temp/graphique_min_max_moyenne.png'

# Utilisation de ';' comme délimiteur
set datafile separator ";"

# Configuration des axes et du titre
set xlabel "Identifiant du trajet"
set ylabel "Distance en km"
set title "Min-Max-Moyenne des distances pour chaque trajet"

# Configuration des couleurs
min_max_color = "#22b240"
moyenne_color = "#004e02"

# Tri des données par la colonne 6 (distance_maxi - distance_mini) par ordre décroissant
stats 'temp/amodifier.txt' using (column(5)-column(4)) nooutput
sortfile = 'temp/donnees_traitees_sorted.txt'
system(sprintf("sort -t';' -k6,6nr %s -o %s", 'temp/resultatS.txt', sortfile))

# Tracer la zone entre min et max avec remplissage
plot sortfile using 1:($5-$6):($5+$6) with filledcurves fill solid border lc rgb min_max_color notitle, \
     '' using 1:5 with lines lc rgb moyenne_color title 'Moyenne', \
     '' using 1:5:6 with yerrorbars title 'Min-Max' lc rgb min_max_color

# Supprimer le fichier temporaire de tri
system(sprintf("rm %s", sortfile))