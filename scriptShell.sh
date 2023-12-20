#!/bash/bin
#verifie + crée si non existant les fichiers temp et image
mkdir -v temp 
mkdir -v image

echo "-------------------------------------------------"
echo "$a"

case $2 in 
  *-d1*) echo "d1";;  
  *-d2*) echo "d2";;  
  *-l*) echo "l";;
  *-t*) echo "t";;
  *-s*) echo "s";;
  *) echo "traitement non valable";; 
  esac

function aide {
  echo "lancez aide.sh si vous avez besoin d'aide"
}

aide
#compile et lance main.c ( sans arguments, a modifier si possible)
gcc -o exe progc/main.c
./exe