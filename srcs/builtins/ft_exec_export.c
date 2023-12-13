/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:54:40 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 19:27:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_cpy(char **cpy)
{
	while (*(*cpy) && *(*cpy) != '=')
		(*cpy)++;
	if (!*(*cpy))
		return (false);
	(*cpy)++;
	return (true);
}

static void	ft_does_value_exist(char *var)
{
	if (ft_find_value(var))
		ft_del_from_env(var);
}

static char	*ft_copy_key_and_equal(char *var, char *new_key)
{
	int	equal_pos;
	int	i;

	equal_pos = ft_get_equal_pos(var);
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

int	ft_exec_export(t_token *token)
{
	char	*nk;
	char	*cpy;

	while (token)
	{
		if (!token)
			return (true);
		if (!ft_strchr_bool(token->word, '=') && token->next == NULL)
			return (true);
		else if (!ft_strchr_bool(token->word, '='))
			token = token->next;
		cpy = token->word;
		if (ft_isdigit(*cpy) == 1 || token->word[0] == '=')
			return (g_error = 1, ft_print_export_error(cpy), true);
		if (!ft_check_cpy(&cpy))
			return (true);
		cpy = ((nk = ft_copy_key_and_equal(token->word, nk), ft_strdup(cpy)));
		free(token->word);
		ft_value_check(nk);
		token->word = ft_strjoin(nk, cpy);
		free(nk);
		free(cpy);
		token = ((ft_add_to_env(token->word)), token->next);
	}
	return (true);
}
