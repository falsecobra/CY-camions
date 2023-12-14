#!/bash/bin
#verifie + crée si non existant les fichiers temp et image
mkdir -v temp 
mkdir -v image


#compile et lance main.c ( sans arguments, a modifier si possible)
gcc -o exe progc/main.c
./exe