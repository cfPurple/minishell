/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:43:46 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:19:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *var)
{
	int		nb_quotes;
	char	*tmp;
	char	*no_quotes;

	tmp = ((nb_quotes = 0, var));
	while (*var)
	{
		if (*var == '\'' || *var == '"')
			nb_quotes++;
		var++;
	}
	if (!*var)
		return (ft_strdup(tmp));
	var = tmp;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(var) - nb_quotes));
	if (!tmp)
		return (NULL);
	no_quotes = ((tmp[ft_strlen(var) - nb_quotes] = '\0', tmp));
	while (*var)
	{
		if (*var != '\'' && *var != '"')
			tmp += ((*tmp = *var, 1));
		++var;
	}
	return (no_quotes);
}

static int	str_is_digit(char **str)
{
	int		tr;
	char	*tmp;

	tr = false;
	tmp = *str;
	*str = remove_quotes(*str);
	free(tmp);
	tmp = *str;
	while (*tmp)
	{
		if (ft_isdigit(*tmp))
			tr = true;
		++tmp;
	}
	if (!tr)
		return (false);
	return (true);
}

// vérifie la valeur d'exit et termine le programme

int	exec_exit(t_token *token, t_cmd *cmd)
{
	int	exit_value;

	if (cmd->fd[0] != STDIN_FILENO || cmd->fd[1] != STDOUT_FILENO)
		return (g_error = 0, true);
	exit_value = g_error;
	if (token)
	{
		if (str_is_digit(&token->word))
			exit_value = ft_atoi(token->word);
		else
			exit(print_exit_error(cmd, token->word));
	}
	if (get_token_len(token) > 1)
		return (g_error = 1, ft_putstr_fd(ERROR_TO_MANY, STDERR_FILENO), true);
	free_cmd(cmd);
	del_env();
	rl_clear_history();
	exit(exit_value);
	return (g_error = 1, true);
}
