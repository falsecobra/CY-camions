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
	$(CC) -o temp/exeL progc/traitementL.c progc/traitementL.h $(CFLAGS)

traitementT: progc/traitementT.c progc/traitementT.h
	$(CC) -o temp/exeT progc/traitementT.c progc/traitementT.h $(CFLAGS)
	
traitementS: progc/traitementS.c progc/traitementS.h
	$(CC) -o temp/exeS progc/traitementS.c progc/traitementS.h $(CFLAGS)
	
clean:
	rm -rf temp