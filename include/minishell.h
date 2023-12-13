/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:52:13 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/01 13:04:27 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define ERROR_RED "No such file or directory\n"
# define ERROR_ARG_CD "Wrong number of argument\n"
# define ERROR_EXP_START "export: "
# define ERROR_EXP_END "': not a valid identifier\n"
# define ERROR_TO_MANY "$> bash: exit: too many arguments\n"
# define ERROR_FORK "$> bash: fork() function error\n"
# define ERROR_POINT_SLASH "$> bash: ./: Is a directory\n"
# define ERROR_CMD ": command not found\n"

# define ERROR -1
# define SUCCESS 0
# define IN 0
# define OUT 1

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

/**********PARSING**********/
int		parse_line(char *str);
int		line_to_token(char *str);
int		line_to_tab(char *str);

/**********UTILS************/
int		check_open_quotes(char *str);
int		ft_print_error_msg(char *msg);
void	ft_print_export_error(char *err);
void	ft_print_unset_error(char *err);
int		ft_print_exit_error(t_cmd *cmd, char *var);
int		nbr_of_token(char *str);
int		is_quote_heredoc(t_token *rdir);
int		get_tab_len(char **tab);
int		ft_get_equal_pos(char *var);
int		ft_get_token_len(t_token *token);
char	*ft_join_slash(char	const *s1, char	const *s2);
char	*ft_join_all_str(char **split);
int		ft_run_builtins(char *path, t_cmd *cmd);
bool	ft_strchr_bool(const char *s, int c);
void	ft_free_tabs(char **tab);
void	ft_del_tokens(t_token *tokens);
void	free_2_tabs(char **s1, char **s2);
void	ft_free_cmd(t_cmd *cmd);
void	ft_del_t_cmd(t_cmd *cmd);
t_token	*ft_delete_all(t_token **node);
t_token	*goto_last_node(t_token *token);
void	dump_add(void *content, t_list *garbage);
void	dump_del(t_list *garbage);
char	**join_paths(char **split_path, char *c);
void	ft_print_sig_error(void);
/***********EXEC************/
void	exec(t_token *token);
void	exec_launch(t_cmd *cmd);
int		exec_new(t_cmd **cmd);
int		exec_list_create(t_cmd **cmd, t_token *token);
int		exec_rdir(t_cmd *cmd);
int		exec_rdir_heredoc(t_cmd *cmd);
void	exec_fork(t_cmd *cmd, t_cmd *start);
void	ft_sig_heredoc(int sig);
void	ft_init_signal(int type);
char	*expand_heredoc_var(char *line);
char	*init_path(char *cmd);
int		ft_exec_echo(t_token *token, int fd);
int		ft_exec_cd(t_token *token, int in, int out);
int		ft_exec_pwd(int fd);
int		ft_exec_export(t_token *token);
int		ft_exec_unset(t_token *token);
int		ft_exec_env(int fd);
int		ft_exec_exit(t_token *token, t_cmd *cmd);
/***********EXPAND************/
char	*expand_var(char *word);
int		dollar_word_count(char *str);
char	*expand_heredoc_var(char *line);

#endif