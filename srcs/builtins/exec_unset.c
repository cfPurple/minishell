/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:30:40 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:55:59 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_var_unset(char *var)
{
	while (*var)
	{
		if (!ft_isalpha(*var) && !ft_isdigit(*var) && *var != '_')
			return (false);
		var++;
	}
	return (true);
}

// supprime une variable de l'env

int	exec_unset(t_token *token)
{
	while (token)
	{
		if (!check_var_unset(token->word))
			print_unset_error(token->word);
		else
			del_from_env(token->word);
		token = token->next;
	}
	return (g_error = 0, true);
}
