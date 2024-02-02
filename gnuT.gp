reset
#ce gnu est modifié et adapté de chatgtp
# Spécifie le terminal de sortie et le nom du fichier
set terminal pngcairo size 1400,1000 enhanced font 'Verdana,12'
set output 'image/imgT.png'

set datafile separator ";"
# Spécifie le style de l'histogramme regroupé
set style data histograms
set style fill solid border -1
set style histogram cluster gap 1

# Spécifie les titres des axes
set xlabel "Noms des Villes"
set ylabel "Nombre de Routes"
set x2label "Option -t"

# Spécifie les marges
set bmargin 5
set lmargin 9

# Charge les données depuis le fichier texte
plot 'temp/amodifier.txt' using 2:xticlabels(1) title "Nombre de Trajets"lc rgb '#d7ccc8 ', '' using 3 title "Premiere ville"lc rgb '#795548'