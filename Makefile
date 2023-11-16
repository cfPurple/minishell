# Nom du projet
NAME := minishell

# Dossier source
SRC_DIR := srcs

# Dossier include
INC_DIR := include

# Dossier des fichiers objets
OBJ_DIR := objs

# Liste des fichiers source
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Liste des fichiers objets correspondants
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Flags de compilation
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR)


all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f $(OBJ_DIR)/*.o
fclean:
	rm -f $(NAME)

.PHONY: clean