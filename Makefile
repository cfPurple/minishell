# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:30:26 by rdias-ba          #+#    #+#              #
#    Updated: 2023/12/15 18:41:56 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

BUILTINS_DIR	= builtins/
BUILTINS_FILES	= exec_cd.c \
				  exec_echo.c \
				  exec_env.c \
				  exec_exit.c \
				  exec_export.c \
				  exec_pwd.c \
				  exec_unset.c \
				  
BUILTINS		= $(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))

ENV_DIR			= env/
ENV_FILES	    = add_var_to_env.c \
				  compare_keys.c \
				  convert_env_to_tab.c \
				  create_env_list.c \
				  del_env.c \
				  del_node.c \
				  find_value.c \
				  get_env_len.c \
				  get_env_utils.c \
				  get_env.c \
				  get_key_len.c \
				  get_key_section.c \
				  get_last_env.c \
				  get_shlvl.c \
				  get_value_len.c \
				  get_value_section.c \
				  
ENV		= $(addprefix $(ENV_DIR), $(ENV_FILES))

EXEC_DIR		= exec/
EXEC_FILES	    = exec_fork.c \
				  exec_heredoc.c \
				  exec_init.c \
				  exec_launch.c \
				  exec_rdir.c \
				  exec_sig_heredoc.c \
				  exec_utils.c \
				  exec_utils2.c \
				  exec.c \
				  
EXEC		= $(addprefix $(EXEC_DIR), $(EXEC_FILES))

EXPANDER_DIR	= expander/
EXPANDER_FILES	= expander.c \
				  qworld_explander.c \
				  var_expander.c \
				  var_to_env_value.c \
				  var_to_value.c \
				  word_expander.c \

				  
EXPANDER		= $(addprefix $(EXPANDER_DIR), $(EXPANDER_FILES))

PARSER_DIR		= parser/
PARSER_FILES	= conv_in_token.c \
				  display_and_read.c \
				  line_parsing.c \
				  parsing_check.c \
				  str_to_tab.c \
				  str_to_token.c \
				  tab_to_token.c \
				  
PARSER		= $(addprefix $(PARSER_DIR), $(PARSER_FILES))

UTILS_DIR		= utils/
UTILS_FILES	    = add_new_node.c \
				  add_type.c \
				  builtins.c \
				  check_quotes.c \
				  check_spaces.c \
				  check_token.c \
				  count_dollar_word.c \
				  count_word.c \
				  create_new_node.c \
				  del_t_cmd.c \
				  delete_all.c \
				  dollar_word_to_tab.c \
				  dump_add.c \
				  dump_del.c \
				  end_of_dollar_word.c \
				  end_of_qword.c \
				  end_of_word.c \
				  free_all_env.c \
				  free_all_token.c \
				  free_cmd.c \
				  free_tab.c \
				  free_tabs.c \
				  ft_lstlast_token.c \
				  ft_strcmp.c \
				  ft_tablen.c \
				  get_equal_pos.c \
				  get_tab_len.c \
				  get_token_len.c \
				  goto_last_node.c \
				  join_free.c \
				  join_paths.c \
				  join_slash.c \
				  join_str.c \
				  join_str2.c \
				  last_token.c \
				  minishell.c \
				  nbr_of_token.c \
				  open_quote.c \
				  print_error_msg.c \
				  print_exit_error.c \
				  print_export_error.c \
				  print_pars_err.c \
				  print_sig_error.c \
				  print_unset_error.c \
				  quote_type.c \
				  quote_utils.c \
				  qvar_explander.c \
				  qword_to_tab.c \
				  remove_quote.c \
				  replace_world.c \
				  start_of_qword.c \
				  expand_heredoc_var.c \
				  start_of_word.c \
				  strchr_bool.c \
				  token_add_back.c \
				  
UTILS		= $(addprefix $(UTILS_DIR), $(UTILS_FILES))

CC			= cc
INCLUDE		= ./include/
CFLAGS		= -Wall -Werror -Wextra -g3
IFLAGS		= -I $(INCLUDE)
RM 			= rm -r -f

LIB_DIR		= ./libft
LIBFT		= $(LIB_DIR)/libft.a
MAKE_LIB	= make -C $(LIB_DIR)

SRCS_DIR	= ./srcs
SRCS_FILES    = $(BUILTINS) \
				$(ENV) \
				$(EXEC) \
				$(EXPANDER) \
				$(PARSER) \
				$(UTILS) \
				main.c

SRCS		= $(SRCS_FILES:%=$(SRCS_DIR)/%)

BUILD_DIR	= objs
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c 
			mkdir -p $(@D)
			$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE_LIB)

clean:
	$(RM) $(BUILD_DIR) $(OBJS)
	$(MAKE_LIB) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LIB) fclean

re: fclean
	make all
	$(MAKE_LIB) re

.PHONY: all clean fclean re
