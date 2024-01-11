#!/bash/bin
#verifie + crée si non existant les fichiers temp et image
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
      cut -d';' -f1,6 "$1" | sort -u | cut -d';' -f2 | sort | uniq -c | sort -n -r | head -10 > temp/tempNB.txt # cette ligne prends l'id trajet et le nom des conducteurs [cut] pour les trier une premiere fois. 
      #[sort -u] et ce tout en supprimant les lignes en double afin de ne pas compter deux fois les conducteurs ayant fais le meme trajet.
      #ensuite on prends seulement la colonne des conducteurs [cut] et on les retrie [sort]
      #[uniq -c] permet de compter le nombre de repetetition, on trie du plus grand au plus petit [sort] puis on envoie les 10 premieres lignes [head] dans un fichier temporaire nommée tempNB.txt
      echo "traitement d1 effectué";;
      *-d2*) 
      cut -d';' -f5,6 "$1" 
      #additionner les km
      sort -n -r | head -10 > temp/tempNB.txt
      echo "d2";;
      *-l*) cut -d',' -f6 "$1" | sort | uniq -c | sort -n -r > temp/tempNB.txt;;
      *-t*) echo "t";;
      *-s*) echo "s";;
      *-h*) echo "
      Ce programmme permet de faire différent traitement sur votre base de donnée. Le premier argument doit être un fichier csv et le deuxième un des différents traitements disponible : 
      -d2 : conducteurs avec le plus de trajets.
      -d1 : conducteurs et la plus grande distance.
      -l :les 10 trajets les plus long.
      -t : les 10 villes les plus traversées.
      -s : statistiques sur les étapes.
      -h : aide et informations sur les commandes.
      --------------------------------------
      votre commande devrait etre de forme [bash scriptShell.sh votrefichier.csv -traitement]" ;;
      *-h*) echo ;;
      *) echo "traitement non valable";; # par default
      esac;;
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
gcc -o temp/exe progc/main.c
./temp/exe
#rm -r temp // a rajt qd on ferra les images

