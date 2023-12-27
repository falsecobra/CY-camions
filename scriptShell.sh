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
      sort -t';' -k 6 | uniq -u "$1" | cut -d';' -f 6  | uniq -c > temp/tempNB.txt #prends les lignes unique, prends seulement la derniere colonne, la trie puis compte combien de fois il apparait.
      #gcc -o temp/exeD1 progc/traitementD1.c
      #./temp/exeD1 temp/tempD1.txt
      sort -t ';' -k1,1 -n -r temp/tempNB.txt| head -10 > demo/resultat.txt
      echo "traitement d1 effectué";;  
      *-d2*) echo "d2";;  
      *-l*) echo "l";;
      *-t*) echo "t";;
      *-s*) echo "s";;
      *-h*) echo "-d2 : liste des 10 plus gros fichiers, -d1 : liste des 10 plus petits fichiers, -l : liste des fichiers par extension, -t : liste des fichiers par date, -s : liste des fichiers par taille, -h : aide" ;;
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