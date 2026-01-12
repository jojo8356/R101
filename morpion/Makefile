# Makefile pour le jeu du Morpion

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

# Dossiers
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
OBJ_DIR = lib.o

# Cible
TARGET = $(BIN_DIR)/morpion

# Fichiers objets
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/ui.o $(OBJ_DIR)/verifs.o $(OBJ_DIR)/jeu.o

# Includes
INCLUDES = -I$(LIB_DIR)

# Règle par défaut
all: dirs $(TARGET)

# Création des dossiers
dirs:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers objets
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(LIB_DIR)/config.h $(LIB_DIR)/ui.h $(LIB_DIR)/verifs.h $(LIB_DIR)/jeu.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/ui.o: $(SRC_DIR)/ui.c $(LIB_DIR)/ui.h $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ui.c -o $(OBJ_DIR)/ui.o

$(OBJ_DIR)/verifs.o: $(SRC_DIR)/verifs.c $(LIB_DIR)/verifs.h $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/verifs.c -o $(OBJ_DIR)/verifs.o

$(OBJ_DIR)/jeu.o: $(SRC_DIR)/jeu.c $(LIB_DIR)/jeu.h $(LIB_DIR)/ui.h $(LIB_DIR)/verifs.h $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/jeu.c -o $(OBJ_DIR)/jeu.o

# Nettoyage
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Nettoyage complet
distclean: clean
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Exécution
run: $(TARGET)
	./$(TARGET)

.PHONY: all dirs clean distclean run
