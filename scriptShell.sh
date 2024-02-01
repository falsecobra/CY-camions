#!/bash/bin
function err {  # permet d'utiliser erreur
	return 1
}

function erreur { #verifie si erreur
	if [ $? -ne 0 ]; then
	echo "Erreur code retour : 1"
	exit 1
	else
	echo "... reussie"
	fi
}

function aide { 
echo "
- - - - - - [AIDE] - - - - - - -"
  echo "
  Ce programmme permet de faire différent traitement sur votre base de donnée. Le premier argument doit être un fichier csv et le deuxième un des différents traitements disponible : "
  echo "-d1 : conducteurs et la plus grande distance."
  echo "-d2 : conducteurs avec le plus de trajets."
  echo "-l :les 10 trajets les plus long."
  echo "-t : les 10 villes les plus traversées."
  echo "-s : statistiques sur les étapes."
  echo "-h : aide et informations sur les commandes.
  "
  echo "--------------------------------------
  "
  echo "votre commande devra etre de forme [bash scriptShell.sh votrefichier.csv -traitement]
  "
}


		


# le main

echo "
- - - - - - Mise en place - - - - - - -
"

mkdir -v temp #création des fichiers temp et image
mkdir -v image
TIMEFORMAT=%R #permet de garder seulement la valeurs réel lorqu'on utilise "time"
	case $# in #sécurise le code si il y a pas assez d'arguments ou trop. Permet aussi de rentrer dans la fonction -h
		1)
		case $1 in
			*-h*)
			aide
			err
			erreur;;
			*)
			echo "
Vous devez mettre plus d'un argument.
faire [-h] pour plus d'information
"
			err
			erreur;;
		esac;;
		2)
		case $2 in
			*-h)
			aide
			err
			erreur;;
		esac;;
		*)
		if [[ $# -ge 3 ]]; then
		  echo "seul les deux premiers arguments ( lien vers le fichier et le traitement sont pris en compte )"
		fi;;
	esac
echo "
- - - - - - Choix du traitement - - - - - -
"

case $1 in # switch avec les differentes commandes
	  *.csv)
	    		case $2 in # trie en fonction du plus routes parcouru.
	      *-d1*) 
	      echo "temps de traitement en seconde :"
	      time cut -d';' -f1,6 "$1" | sort -S 50% -u | cut -d';' -f2 | sort -S 50% | uniq -c | sort -S 50% -n -r | head -10 > temp/tempD1.txt
	      sed -i 's/\([0-9]\) \([A-Za-z]\)/\1;\2/g' temp/tempD1.txt 
	      sed 's/;/ ; /g' temp/tempD1.txt > temp/tempNB.txt
	      gnuplot gnuD1.gp
	      convert -rotate 90 image/imgD1.png image/imgD1.png
	      xdg-open image/imgD1.png
	      # chat gtp ! permet de délimiter les conducteurs avec les trajet
	       # cette ligne prends l'id trajet et le nom des conducteurs [cut] pour les trier une premiere fois. 
	      #[sort -u] et ce tout en supprimant les lignes en double afin de ne pas compter deux fois les conducteurs ayant fais le meme trajet.
	      #ensuite on prends seulement la colonne des conducteurs [cut] et on les retrie [sort]
	      #[uniq -c] permet de compter le nombre de repetetition, on trie du plus grand au plus petit [sort] puis on envoie les 10 premieres lignes [head] dans un fichier temporaire nommée tempNB.txt
	      echo "
traitement d1 effectué";;
	      *-d2*) 
	      time cut -d';' -f5,6 "$1" | awk -F';' '{conducteurs[$2]+=$1} END {for (km in conducteurs) print conducteurs[km], ";", km}' | sort -S 50% -n -r | head -10 > temp/tempD2.txt
	      gnuplot gnuD2.gp
	      convert -rotate 90 image/imgD2.png image/imgD2.png
	      xdg-open image/imgD2.png
	 # tout comme le premier traitement on prends les colonnes qui nous interessent ( 5 les km et 6 les conducteurs ). La fonction awk viens d'un forum CommentçaMarche datant de 2014. Ensuite on trie numériquement et on inverse pour enfin garder seulement les 10 premiers conducteurs que l'on met dans un fichier temporaire.

	      echo "
traitement d2 effectué";;
	      *-l*) make traitementL
	      ./temp/exeL $1 progc/amodifier.csv
	      mv progc/amodifier.csv temp/
	      gnuplot gnuL.gp
	      xdg-open image/imgL.png
	      echo "l";;
	      *-t*) make traitementT
	      ./temp/exeT $1 progc/amodifier.csv
	      mv progc/amodifier.txt temp/
	      echo "t";;
	      *-s*) make traitementS
	      ./temp/exeS $1 progc/amodifier.csv
	      mv progc/amodifier.txt temp/
	      chmod +x gnuS.gp
	      gnuplot gnuS.gp

	      echo "s";;
	      *-h*) aide ;;
	      *) echo "traitement non valable";; # par default
	      esac;;
	  *) 
	  echo "veuillez mettre le csv en premier argument"
	  # si le premier argument n'est pas dans le bon format
	  err
	  erreur;;
	esac


echo "
- - - - - - Fin de programme - - - - - -
"

#compile et lance main.c ( sans arguments, a modifier si possible)
mv temp/amodifier.txt progc/
make clean
#rm -r temp // a rajt qd on ferra les images

