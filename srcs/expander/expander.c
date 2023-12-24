/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:20:01 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expander(t_token *token_list)
{
	t_token	*token;

	token = token_list;
	while (token)
	{
		if ((token->type == WORD || token->type == FD)
			&& (ft_strchr(token->word, '\"') || ft_strchr(token->word, '\'')))
		{
			if (qword_expander(token) == ERROR)
				return (ERROR);
		}
		else if ((token->type == WORD || token->type == FD))
		{
			if (word_expander(token) == ERROR)
				return (ERROR);
		}
		token = token->next;
	}
	exec(token_list);
	return (SUCCESS);
}
