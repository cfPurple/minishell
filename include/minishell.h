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
	HEREDOC,
	LIMITOR,
    R_IN,
	R_OUT,
	PIPE,
    FD,
	WORD,
    APPEND = 0,
}				t_type;

extern int	g_error;

int main(int ac, char **av);

/**********PARSING**********/
int parse_line(char *str);
int line_to_token(char *str);
int line_to_tab(char *str);

/**********UTILS************/
int check_open_quotes(char *str);
int nbr_of_token(char *str);

#endif