# Makefile pour le jeu Juste Prix

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

# Dossiers
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
OBJ_DIR = lib.o
ASSETS_DIR = assets

# Cible
TARGET = $(BIN_DIR)/juste_prix

# Fichiers objets (dans lib.o)
OBJ = $(OBJ_DIR)/main.o
LIB_OBJS = $(OBJ_DIR)/config.o $(OBJ_DIR)/dict.o $(OBJ_DIR)/ui.o

# Includes
INCLUDES = -I$(LIB_DIR)

# Règle par défaut
all: dirs $(TARGET)

# Création des dossiers
dirs:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

# Compilation de l'exécutable
$(TARGET): $(OBJ) $(LIB_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIB_OBJS)

# Compilation des fichiers objets
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(LIB_DIR)/config.h $(LIB_DIR)/dict.h $(LIB_DIR)/ui.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/config.o: $(SRC_DIR)/config.c $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/config.c -o $(OBJ_DIR)/config.o

$(OBJ_DIR)/dict.o: $(SRC_DIR)/dict.c $(LIB_DIR)/dict.h $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/dict.c -o $(OBJ_DIR)/dict.o

$(OBJ_DIR)/ui.o: $(SRC_DIR)/ui.c $(LIB_DIR)/ui.h $(LIB_DIR)/dict.h $(LIB_DIR)/config.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ui.c -o $(OBJ_DIR)/ui.o

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
