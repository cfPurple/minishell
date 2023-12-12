#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

#define ERROR -1
#define SUCCESS 0

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*next;
}               t_token;

typedef enum e_type
{
	APPEND = 0,
	HEREDOC,
	LIMITOR,
    R_IN,
	R_OUT,
	PIPE,
    FD,
	WORD,

}				t_type;

extern int	g_error;

int main(int ac, char **av);

/**********PARSING**********/
int		parse_line(char *str);
int		line_to_token(char *str);
int		line_to_tab(char *str);
t_token	*tab_to_token( char **tab);
int		tokenizer(t_token *token);
int		parsing_check(t_token *token);

/**********EXPANDER*********/
int		expander(t_token *token_list);


/**********UTILS************/
int 	check_open_quotes(char *str);
int 	nbr_of_token(char *str);
int 	start_of_word(char *str ,int i);
int 	end_of_word(char *str ,int start);
t_token	*create_new_node(char *str);
int		add_new_node(t_token *cmd_line, char *line);
void	token_add_back(t_token **lst, t_token *new);
t_token	*last_token(t_token *lst);
int		add_type(char *str, int last_token);
int		check_token(t_type token, t_type last_token);
void    print_pars_err(char *str);

#endif