#ce gnu est modifié et adapté de chatgtp

# Configuration du terminal de sortie (par exemple, PNG)
set terminal pngcairo size 2000,1300
set output 'image/imgS.png'

# Utilisation de ';' comme délimiteur
set datafile separator ";"

# Configuration des axes et du titre
set xlabel "Identifiant du trajet"
set ylabel "Distance en km"
set title "Min-Max-Moyenne des distances pour chaque trajet"
set xtics rotate by -45 offset -1,-0,5

# Configuration des couleurs
min_max_color = "#d7ccc8"
moyenne_color = "#004e02"
white = "#ffffff"

# Spécifie les marges
set bmargin 5
set lmargin 11

set style data points



# Tracer la zone entre min et max avec remplissage // a partir d'ici tout est fais a la main
plot 'temp/amodifier.txt'  using 1:3:5  with filledcurves fill solid border fc rgb '#d7ccc8' title 'Max/Min(km)' , ''u 4 w lines lc rgb '#795548'  title 'moyenne (km)', '' u 1:xtic(2) w dots lc rgb 'white' notitle
#ordre;idtrajet;distancemin;distancemoy;
#distancemax;distancemax-distancemin