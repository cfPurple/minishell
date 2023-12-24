/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:03:47 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:07:44 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define ERROR -1
# define SUCCESS 0
# define IN 0
# define OUT 1

# define ERROR_STOP "Something wrong happened forcing Minishell to stop\n"
# define ERROR_PARSING "$> bash : syntax error near unexpected token"
# define ERROR_RED " No such file or directory\n"
# define ERROR_ARG_CD " Wrong number of argument\n"
# define ERROR_EXP_START "export: "
# define ERROR_EXP_END "': not a valid identifier\n"
# define ERROR_TO_MANY "$> bash: exit: too many arguments\n"
# define ERROR_FORK "$> bash: fork() function error\n"
# define ERROR_POINT_SLASH "$> bash: ./: Is a directory\n"
# define ERROR_CMD ": command not found\n"

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

typedef enum e_quote
{
	NOQUOTE = 0,
	SQUOTE,
	DQUOTE
}				t_quote;

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*next;
}				t_token;

typedef struct s_cmd
{
	t_token			*args;
	t_token			*rdir;
	int				fd[2];
	int				pid;
	struct s_cmd	*next;

}				t_cmd;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

extern int	g_error;

int		main(int ac, char **av, char **env);

/**********PARSING**********/
int		display_and_read(void);
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
char	*var_to_env_value(char *word);

/***********EXEC************/
void	exec(t_token *token);
void	exec_launch(t_cmd *cmd);
int		exec_new(t_cmd **cmd);
int		exec_list_create(t_cmd **cmd, t_token *token);
int		exec_rdir(t_cmd *cmd);
int		exec_rdir_heredoc(t_cmd *cmd);
void	exec_fork(t_cmd *cmd, t_cmd *start);
void	sig_heredoc(int sig);
void	init_signal(int type);
char	*expand_heredoc_var(char *line);
char	*init_path(char *cmd);
int		exec_echo(t_token *token, int fd);
int		exec_cd(t_token *token, int in, int out);
int		exec_pwd(int fd);
int		exec_export(t_token *token);
int		exec_unset(t_token *token);
int		exec_env(int fd);
int		exec_exit(t_token *token, t_cmd *cmd);
char	**convert_args_to_tab(t_token *args);
int		only_num(char *str);
int		check_char(char *str);

/***********ENV************/
t_env	**get_env(char **env, char *to_add, char *to_del);
t_env	*get_last_env(t_env *env);
char	*env_init_var(t_env **env, char *to_add);
int		compare_keys(char *key, char *to_find);
char	**convert_env_to_tab(t_env *env);
t_env	*create_env_list(char **env);
void	del_env(void);
t_env	*del_node(t_env *env, char *to_del);
char	*find_value(char *var);
int		get_env_len(t_env *env);
void	init_env(int ac, char **av, char **env);
void	add_to_env(char *to_add);
void	del_from_env(char *to_del);
t_env	**get_all_env(void);
int		get_key_len(char *var);
char	*get_key_section(char *var, char *key);
int		get_value_len(char *var);
char	*get_value_section(char *var, char *value);
void	get_shlvl(void);

/**********UTILS************/
void	minishell(int ac, char **av, char **env);
int		check_quotes(char *str);
int		check_spaces(char *str);
int		nbr_of_token(char *str);
int		start_of_word(char *str, int i);
int		end_of_word(char *str, int start);
t_token	*create_new_node(char *str);
int		add_new_node(t_token *cmd_line, char *line);
void	token_add_back(t_token **lst, t_token *new);
t_token	*ft_lstlast_token(t_token *lst);
t_token	*last_token(t_token *lst);
int		add_type(char *str, int last_token);
int		check_token(t_type token, t_type last_token);
void	print_pars_err(char *str);
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
void	replace_word(t_token *token, char *new_word);
int		is_quote_heredoc(t_token *rdir);
int		get_tab_len(char **tab);
int		get_equal_pos(char *var);
int		get_token_len(t_token *token);
char	*join_slash(char	const *s1, char	const *s2);
char	*join_all_str(char **split);
int		builtins(char *path, t_cmd *cmd);
bool	strchr_bool(const char *s, int c);
void	del_tokens(t_token *tokens);
void	free_cmd(t_cmd *cmd);
void	free_all_env(t_env *env);
void	del_t_cmd(t_cmd *cmd);
t_token	*goto_last_node(t_token *token);
void	dump_add(void *content, t_list *garbage);
void	dump_del(t_list *garbage);
char	**join_paths(char **split_path, char *c);
void	print_sig_error(void);
int		print_error_msg(char *msg);
void	print_export_error(char *err);
void	print_unset_error(char *err);
int		print_exit_error(t_cmd *cmd, char *var);
int		ft_strcmp(char *s1, char *s2);

#endif
