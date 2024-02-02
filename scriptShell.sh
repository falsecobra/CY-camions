#!/bash/bin
export LC_NUMERIC="en_US.UTF-8" # flottants
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

mkdir -v temp #création des fichiers temp et image et data
mkdir -v image
mkdir -v data
touch progc/amodifier.txt # pour le fonctionnement des programmes en c
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
case $1 in # switch pour securiser encore un fois mais le premier arguments seulement cette fois ci + copie data
	  *.csv)
	  if [ -e "$1" ]; then
	  	echo "copie du fichier data..."
		cp $1 data/data.csv #copie le csv envoyé dans data/
		cp data/data.csv progc/
		else
		echo "Erreur : Ce fichier .csv n'existe pas."
		err
	  	erreur
	  	fi;;
	  	  *) 
	  echo "veuillez mettre le csv en premier argument"
	  # si le premier argument n'est pas dans le bon format
	  err
	  erreur;;
	esac

echo "

- - - - - - Choix du traitement - - - - - -
"

case $1 in # switch avec les differentes commandes
	  *.csv)
	    		case $2 in # trie en fonction du plus routes parcouru.
	      *-d1*) 
	      echo "temps de traitement en seconde :"
	      time cut -d';' -f1,6 "$1" | sort -S 50% -u | cut -d';' -f2 | sort -S 50% | uniq -c | sort -S 50% -n -r | head -10 > temp/resD1.txt
	       # cette ligne prends l'id trajet et le nom des conducteurs [cut] pour les trier une premiere fois. 
	      #[sort -u] et ce tout en supprimant les lignes en double afin de ne pas compter deux fois les conducteurs ayant fais le meme trajet.
	      #ensuite on prends seulement la colonne des conducteurs [cut] et on les retrie [sort]
	      #[uniq -c] permet de compter le nombre de repetetition, on trie du plus grand au plus petit [sort] puis on envoie les 10 premieres lignes [head] dans un fichier temporaire nommée tempNB.txt
	      sed -i 's/\([0-9]\) \([A-Za-z]\)/\1;\2/g' temp/resD1.txt 
	      # chat gtp ! permet de délimiter les conducteurs avec les trajet
	      gnuplot gnuD1.gp #envoie a gnuplot
	      convert -rotate 90 image/imgD1.png image/imgD1.png #tourne l'image 
	      xdg-open image/imgD1.png #ouvre l'image
	      echo "
traitement d1 effectué";;
	      *-d2*) 
	      echo "temps de traitement en seconde :"
	      time cut -d';' -f5,6 "$1" | awk -F';' '{conducteurs[$2]+=$1} END {for (km in conducteurs) print conducteurs[km], ";", km}' | sort -S 50% -n -r | head -10 > temp/resD2.txt
	 # tout comme le premier traitement on prends les colonnes qui nous interessent ( 5 les km et 6 les conducteurs ). La fonction awk viens d'un forum CommentçaMarche datant de 2014 ( que j'ai modifié et ajusté). Ensuite on trie numériquement et on inverse pour enfin garder seulement les 10 premiers conducteurs que l'on met dans un fichier temporaire.
	      gnuplot gnuD2.gp #envoie a gnuplot
	      convert -rotate 90 image/imgD2.png image/imgD2.png #tourne l'image 
	      xdg-open image/imgD2.png #ouvre l'image

	      echo "
traitement d2 effectué";;
	      *-l*) make traitementL #compile, execute, transmet a gnuplot puis ouvre l'image
	      ./temp/exeL $1 progc/amodifier.txt
	      mv progc/amodifier.txt temp/
	      gnuplot gnuL.gp
	      xdg-open image/imgL.png
	      mv temp/amodifier.txt temp/resL.txt #renommme le fichier amodifier pour mieux retrouver les resultats.
	      echo "Traitement l effectué";;
	      *-t*) make traitementT #compile, execute, transmet a gnuplot puis ouvre l'image
	      ./temp/exeT $1 progc/amodifier.txt
	      mv progc/amodifier.txt temp/
	      gnuplot gnuT.gp
	      xdg-open image/imgT.png
	      mv temp/amodifier.txt temp/resT.txt #renommme le fichier amodifier pour mieux retrouver les resultats.
	      echo "Traitement t effectué";;
	      *-s*) make traitementS #compile, execute, transmet a gnuplot puis ouvre l'image
	      ./temp/exeS $1 progc/amodifier.txt
	      mv progc/amodifier.txt temp/
	      chmod +x gnuS.gp
	      gnuplot gnuS.gp
	      xdg-open image/imgS.png
	      mv temp/amodifier.txt temp/resS.txt #renommme le fichier amodifier pour mieux retrouver les resultats.
	      echo "Traitement s effectué";;
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
mv progc/data.csv temp/
#compile et lance main.c ( sans arguments, a modifier si possible)
make clean

