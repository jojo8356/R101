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
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compilation des .c en .o
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(SRC_MAIN) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Répertoires nécessaires
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
