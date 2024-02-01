#!/usr/bin/gnuplot
reset

set datafile separator";"
# Spécifie le format de sortie et le nom du fichier
set terminal pngcairo size 1400,1000 enhanced font 'Verdana,12'
set output 'image/imgL.png'

# Spécifie le style de l'histogramme horizontal
set style data histograms
set style fill solid border -1
set xtics format""
set autoscale y
set view 0,90,1
set style histogram cluster gap 1
set yrange[0:*]

#mise en page
set xtics rotate by -270

# Spécifie les titres des axes
set xlabel "Route ID"
set x2label "Option -l"
set ylabel "Distance en Km"
set ylabel offset 0

# Spécifie les marges
set bmargin 5
set lmargin 9



# Charge les données depuis le fichier texte
plot 'temp/amodifier.txt' using 2:xticlabels(1) notitle