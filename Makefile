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
	@echo "compilation en cours..."
	@$(CC) -o temp/exeL progc/traitementL.c progc/traitementL.h $(CFLAGS)
	@echo "compilation terminée."

traitementT: progc/traitementT.c progc/traitementT.h
	@echo "compilation en cours..."
	@$(CC) -o temp/exeT progc/traitementT.c progc/traitementT.h $(CFLAGS)
	@echo "compilation terminée."
	
traitementS: progc/traitementS.c progc/traitementS.h
	@echo "compilation en cours..."
	@$(CC) -o temp/exeS progc/traitementS.c progc/traitementS.h $(CFLAGS)
	@echo "compilation terminée."

clean:
	@echo "Suppression des éléments temporaires..."
	@rm -rf temp
	@echo "Suppression terminée."
