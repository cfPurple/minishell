# Nom du projet
NAME := minishell

# Dossier source
SRC_DIR := srcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

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

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a -lreadline

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean