#!/usr/bin/gnuplot
reset

set datafile separator";"
# Spécifie le format de sortie et le nom du fichier
set terminal pngcairo size 1600,1000 enhanced font 'Verdana,12'
set output 'image/imgD1.png'

# Spécifie le style de l'histogramme horizontal
set style data histograms
set style fill solid border -1
set boxwidth 0.8
set xtics format""
set autoscale y
set view 0,80,1
set style histogram cluster gap 1

#mise en page
set yrange [0:*]
set ytics mirror
set xtics rotate by -270
set ytics rotate by -270 offset 156

# Spécifie les titres des axes
set xlabel "Nom Conduteur"
set ylabel offset 5,0
set xlabel offset 0,1
set ylabel "Option -d1"
set y2label "Trajets"
set y2label offset 3,0

# Spécifie les marges
set bmargin 10
set lmargin 5



# Charge les données depuis le fichier texte
plot 'demo/tempNB.txt' using 1:xticlabels(2) notitle
