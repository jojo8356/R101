# Makefile pour le jeu du Pendu

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

# Dossiers
LIB_DIR = lib

# Cible
TARGET = pendu

# Fichiers objets
OBJS = main.o $(LIB_DIR)/dictionnaire.o $(LIB_DIR)/pendu.o

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers objets
main.o: main.c $(LIB_DIR)/dictionnaire.h $(LIB_DIR)/pendu.h
	$(CC) $(CFLAGS) -c main.c -o main.o

$(LIB_DIR)/dictionnaire.o: $(LIB_DIR)/dictionnaire.c $(LIB_DIR)/dictionnaire.h
	$(CC) $(CFLAGS) -c $(LIB_DIR)/dictionnaire.c -o $(LIB_DIR)/dictionnaire.o

$(LIB_DIR)/pendu.o: $(LIB_DIR)/pendu.c $(LIB_DIR)/pendu.h $(LIB_DIR)/dictionnaire.h
	$(CC) $(CFLAGS) -c $(LIB_DIR)/pendu.c -o $(LIB_DIR)/pendu.o

# Nettoyage
clean:
	rm -f *.o $(LIB_DIR)/*.o $(TARGET)

# Exécution
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
