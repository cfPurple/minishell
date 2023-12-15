/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:51:44 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:51:46 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tab_to_token( char **tab)
{
	t_token	*token_list;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			token_list = create_new_node(tab[0]);
			if (!token_list)
				return (NULL);
		}
		else
			if (add_new_node(token_list, tab[i]) == ERROR)
				return (NULL);
		if (!token_list)
			return (NULL);
		i++;
	}
	return (token_list);
}
