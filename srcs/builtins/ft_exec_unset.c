/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:30:40 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 19:38:54 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_var_unset(char *var)
{
	while (*var)
	{
		if (!ft_isalpha(*var) && !ft_isdigit(*var) && *var != '_')
			return (false);
		var++;
	}
	return (true);
}

int	ft_exec_unset(t_token *token)
{
	while (token)
	{
		if (!ft_check_var_unset(token->word))
			ft_print_unset_error(token->word);
		else
			ft_del_from_env(token->word);
		token = token->next;
	}
	return (g_error = 0, true);
}
