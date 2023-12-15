/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_in_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:50:26 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:50:30 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	conv_in_token(t_token *token)
{
    t_token	*current;
	int		last_token;

	current = token;
	last_token = -1;
	while (current)
	{
		current->type = add_type(current->word, last_token);
		last_token = add_type(current->word, last_token);
		current = current->next;
	}
	if (parsing_check(token) == ERROR)
		return (ERROR);
	else
		return (expander(token));
}
