/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:54:40 by rdias-ba          #+#    #+#             */
/*   Updated: 2024/01/18 11:45:58 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cpy(char **cpy)
{
	while (*(*cpy) && *(*cpy) != '=')
		(*cpy)++;
	if (!*(*cpy))
		return (false);
	(*cpy)++;
	return (true);
}

static void	value_check(char *var)
{
	if (find_value(var))
		del_from_env(var);
}

static char	*copy_key_and_equal(char *var, char *new_key)
{
	int	equal_pos;
	int	i;

	equal_pos = get_equal_pos(var);
	new_key = (char *)malloc(sizeof(char) * (equal_pos + 1));
	if (!new_key)
		return (NULL);
	i = 0;
	while (i < equal_pos)
	{
		new_key[i] = var[i];
		++i;
	}
	new_key[i] = '\0';
	return (new_key);
}

int	exec_export(t_token *token, int fd)
{
	char	*nk;
	char	*cpy;

	if (!token)
		exec_env(fd);
	while (token)
	{
		if (only_num(token->word) == 1 || check_char(token->word) == 1)
			return (g_error = 1, print_export_error(token->word), true);
		if (!strchr_bool(token->word, '=') && token->next == NULL)
			return (true);
		else if (!strchr_bool(token->word, '='))
			token = token->next;
		cpy = token->word;
		if (ft_isdigit(*cpy) == 1 || token->word[0] == '=')
			return (g_error = 1, print_export_error(cpy), true);
		if (!check_cpy(&cpy))
			return (true);
		cpy = ((nk = copy_key_and_equal(token->word, nk), ft_strdup(cpy)));
		(free(token->word), value_check(nk));
		token->word = ft_strjoin(nk, cpy);
		free_export_utils(nk, cpy);
		token = ((add_to_env(token->word)), token->next);
	}
	return (true);
}
