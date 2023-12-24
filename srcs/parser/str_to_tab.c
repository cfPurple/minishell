/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:51:19 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:29:12 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**str_to_tab(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		start;
	int		end;

	tab = ft_calloc(nbr_of_token(str) + 1, sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
	i = 0;
	while (str[i] && j < nbr_of_token(str))
	{
		start = start_of_word(str, i);
		end = end_of_word(str, start);
		tab[j] = ft_substr(str, start, end - start);
		if (!tab[j])
			return (NULL);
		while (str[i] && i < end)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
