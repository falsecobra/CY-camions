all: main

CC = gcc
override CFLAGS += -g -Wno-everything -pthread -lm

##ajout pour compiler les fichier de src directement
DIR_SRC = src/
DIR_INC = src/
SRCS = $(wildcard $(DIR_SRC)*.c)
HEADERS = $(wildcard $(DIR_INC)*.h)


main: $(SRCS) $(HEADERS)
	$(CC) -o "$@" $(SRCS)	$(CFLAGS)


traitementL: progc/traitementL.c progc/traitementL.h
	$(CC) -o temp/exeL progc/traitementL.c $(CFLAGS)

traitementT: progc/traitementT.c progc/traitementT.h
	$(CC) -o temp/exeT progc/traitementT.c $(CFLAGS)
	
traitementS: progc/traitementS.c progc/traitementS.h
	$(CC) -o temp/exeS progc/traitementS.c $(CFLAGS)
	
clean:
	rm -rf temp