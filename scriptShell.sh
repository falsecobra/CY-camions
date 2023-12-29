#!/bash/bin
#verifie + crée si non existant les fichiers temp et image
mkdir -v temp 
mkdir -v image

echo "-------------------------------------------------"
echo "$a"

case $1 in # switch avec les differentes commandes
  *.csv)
    case $2 in # trie en fonction du plus routes parcouru.
      *-d1*) 
      #cut -d';' -f 1,2,6 "$1" > temp/tempD1.txt
      cut -d';' -f1-5,6 "$1" | sort -u | cut -d';' -f6 | sort | uniq -c | sort -n -r | head -10 > temp/tempNB.txt
#prends les lignes unique, prends seulement la derniere colonne, la trie puis compte combien de fois il apparait.
      #gcc -o temp/exeD1 progc/traitementD1.c
      #./temp/exeD1 temp/tempD1.txt
      sort -t ';' -k1,1 -n -r temp/tempNB.txt| head -10 > demo/resultat.txt
      echo "traitement d1 effectué";;  
      *-d2*) echo "d2";;  
      *-l*) echo "l";;
      *-t*) echo "t";;
      *-s*) echo "s";;
      *-h*) echo "-d2 : conducteurs avec le plus de trajets, -d1 : conducteurs et la plus grande distance, -l : les 10 trajets les plus longs, -t : les 10 villes les plus traversées, -s : statistiques sur les étapes, -h : aide et informations sur les commandes" ;;
      *) echo "traitement non valable";; # par default
      esac;;
  *)
  echo "veuillez mettre le csv en premier argument";; # si le premier argument n'est pas dans le bon format
esac

function aide {
  echo "lancez aide.sh si vous avez besoin d'aide"
}

aide
#compile et lance main.c ( sans arguments, a modifier si possible)
gcc -o temp/exe progc/main.c
./temp/exe