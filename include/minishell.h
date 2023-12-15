#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

#define ERROR -1
#define SUCCESS 0

# define ERROR_STOP "Something wrong happened forcing Minishell to stop\n"
# define ERROR_PARSING "$> bash : syntax error near unexpected token"

typedef enum e_type
{
	APPEND = 0,
	HEREDOC,
	LIMITOR,
    R_IN,
	R_OUT,
	PIPE,
    FD,
	WORD
}				t_type;

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*next;
}               t_token;

typedef enum e_quote
{
	NOQUOTE = 0,
	SQUOTE,
	DQUOTE
}				t_quote;

extern int	g_error;

int main(int ac, char **av, char **env);

/**********PARSING**********/
int		line_parsing(char *str);
int		str_to_token(char *str);
char	**str_to_tab(char *str);
t_token	*tab_to_token( char **tab);
int		conv_in_token(t_token *token);
int		parsing_check(t_token *token);

/**********EXPANDER*********/
int		expander(t_token *token_list);
int		qword_expander(t_token *token);
int		word_expander(t_token *token);
char	*qvar_expander(char *str);
char	*var_expander(char *str);


/**********UTILS************/
void 	minishell(int ac, char **av, char **env);
int 	display_and_read(void);
int 	check_quotes(char *str);
int		check_spaces(char *str);
int 	nbr_of_token(char *str);
int 	start_of_word(char *str ,int i);
int 	end_of_word(char *str ,int start);
t_token	*create_new_node(char *str);
int		add_new_node(t_token *cmd_line, char *line);
void	token_add_back(t_token **lst, t_token *new);
t_token	*ft_lstlast_token(t_token *lst);
t_token	*last_token(t_token *lst);
int		add_type(char *str, int last_token);
int		check_token(t_type token, t_type last_token);
void    print_pars_err(char *str);
int		count_word(char *str);
t_token	*free_all_token(t_token **token);
int		start_of_qword(char *str, int i);
int		end_of_qword(char *str, int i);
char	**qword_to_tab(char *str);
int		ft_tablen(char **tab);
void	free_tab(char **tab);
void	free_tabs(char **tab1, char **tab2);
int		quote_type(char c);
char	*join_str(char **str);
char	*join_str2(char *s1, char *s2, char *old_str);
char	*remove_quote(char *str);
char	**dollar_word_to_tab(char *str);
int		count_dollar_word(char *str);
int		end_of_dollar_word(char *str, int i);
char	*var_to_value(char *str);
int		open_quote(char *str, int start);
void    print_pars_err(char *str);
void	replace_word(t_token *token, char *new_word);
char	*var_expander(char *str);
char	*var_to_env_value(char *word);

/*************TEST***************/
void	print_token_list(t_token *lst);




#endif