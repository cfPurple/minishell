/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:51:08 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:30:47 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing_check(t_token *token)
{
	t_token	*last_token;
	t_type	last_token_t;

	last_token_t = -1;
	while (token)
	{
		if (check_token(token->type, last_token_t) == ERROR)
		{
			print_pars_err(token->word);
			return (ERROR);
		}
		last_token = token;
		last_token_t = token->type;
		token = token->next;
	}
	if (last_token_t == R_IN || last_token_t == R_OUT || last_token_t == APPEND
		|| last_token_t == HEREDOC || last_token_t == PIPE)
	{
		print_pars_err(last_token->word);
		return (ERROR);
	}
	return (SUCCESS);
}
