# Compilateur et options
CC      := gcc
CFLAGS  := -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g
LDFLAGS := 

# Répertoires
SRC_DIR := .
LIB_DIR := lib
BIN_DIR := bin
OBJ_DIR := obj

SRC_MAIN := $(SRC_DIR)/main.c
SRC_LIBS := $(wildcard $(LIB_DIR)/*.c)

OBJ_MAIN := $(OBJ_DIR)/main.o
OBJ_LIBS := $(patsubst $(LIB_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_LIBS))
OBJS     := $(OBJ_MAIN) $(OBJ_LIBS)

# Exécutable
TARGET := $(BIN_DIR)/log2report

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS) | $(BIN_DIR) # Crée le répertoire bin si nécessaire
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
# Lie les fichiers objets pour créer l'exécutable

# Compilation des .c en .o
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR) # Crée le répertoire obj si nécessaire
	$(CC) $(CFLAGS) -c $< -o $@
# Compile chaque fichier source en fichier objet

$(OBJ_DIR)/main.o: $(SRC_MAIN) | $(OBJ_DIR) # Crée le répertoire obj si nécessaire
	$(CC) $(CFLAGS) -c $< -o $@ 
# Compile le fichier source principal en fichier objet

# Répertoires nécessaires
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
# Crée les répertoires bin et obj

# Tests unitaires
TEST_SRC := tests/utils.c
TEST_BIN := $(BIN_DIR)/test

test: $(TEST_BIN)
	@echo "🧪 Exécution des tests unitaires..."
	@./$(TEST_BIN)
	@echo "✅ Tests terminés avec succès !"

$(TEST_BIN): $(TEST_SRC) $(SRC_LIBS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
