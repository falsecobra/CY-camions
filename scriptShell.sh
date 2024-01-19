#!/bash/bin
#verifie + crée si non existant les fichiers temp et image
function traitementc {
 echo "traitement en c"
}
function aide {
  echo "/!\ PAS DE TRAITEMENT /!\ [AIDE] :
  Ce programmme permet de faire différent traitement sur votre base de donnée. Le premier argument doit être un fichier csv et le deuxième un des différents traitements disponible : "
  echo "-d2 : conducteurs avec le plus de trajets."
  echo "-d1 : conducteurs et la plus grande distance."
  echo "-l :les 10 trajets les plus long."
  echo "-t : les 10 villes les plus traversées."
  echo "-s : statistiques sur les étapes."
  echo "-h : aide et informations sur les commandes."
  echo "--------------------------------------"
  echo "votre commande devrait etre de forme [bash scriptShell.sh votrefichier.csv -traitement]"
}
echo "
- - - - - - Mise en place - - - - - - -
"
mkdir -v temp 
mkdir -v image

echo "
- - - - - - Choix du traitement - - - - - -
"

if [[ $# -ge 3 ]]; then
  echo "seul les deux premiers arguments ( lien vers le fichier et le traitement sont pris en compte )"
  exit 1
fi
if [[ $# -lt 1 ]]; then
  echo "veuillez ecrire des arguments, [-h] si vous avez besoin d'aide. "
  exit 1
fi
case $1 in # switch avec les differentes commandes
  *.csv)
    case $2 in # trie en fonction du plus routes parcouru.
      *-d1*) 
      time cut -d';' -f1,6 "$1" | sort -u | cut -d';' -f2 | sort | uniq -c | sort -n -r | head -10 > demo/tempNB.txt # cette ligne prends l'id trajet et le nom des conducteurs [cut] pour les trier une premiere fois. 
      #[sort -u] et ce tout en supprimant les lignes en double afin de ne pas compter deux fois les conducteurs ayant fais le meme trajet.
      #ensuite on prends seulement la colonne des conducteurs [cut] et on les retrie [sort]
      #[uniq -c] permet de compter le nombre de repetetition, on trie du plus grand au plus petit [sort] puis on envoie les 10 premieres lignes [head] dans un fichier temporaire nommée tempNB.txt
      echo "traitement d1 effectué";;
      *-d2*) 
      time cut -d';' -f5,6 "$1" | sort -t';' -k2,2 | awk -F';' '{drivers[$2]+=$1} END {for (driver in drivers) print drivers[driver], ";", driver}' | sort -n -r | head -10 > demo/tempNB1.txt
 # tout comme le premier traitement on prends les colonnes qui nous interessent ( 5 les km et 6 les conducteurs ). Ensuite on supprime les lignes en double et on fait la somme des km pour chacun des conducteurs. La fonction awk viens de CHATGPT. Ensuite on trie numériquement et on inverse pour enfin garder seulement les 10 premiers conducteurs que l'on met dans un fichier temporaire.
      echo "traitement d2 effectué";;
      *-l*) make traitementL
      echo "l";;
      *-t*) make traitementT
      echo "t";;
      *-s*) make traitementS
      echo "s";;
      *-h*) aide ;;
      *) echo "traitement non valable";; # par default
      esac;;
  *-h*) aide ;;
  *)
  echo "veuillez mettre le csv en premier argument"
  # si le premier argument n'est pas dans le bon format
  exit 1;;
esac

echo "
- - - - - - Fin de programme - - - - - -
"
echo " temps de traitement : NULL"

#compile et lance main.c ( sans arguments, a modifier si possible)
make clean
#rm -r temp // a rajt qd on ferra les images

