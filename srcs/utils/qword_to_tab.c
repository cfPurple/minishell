/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qword_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:24 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:48:09 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**qword_to_tab(char *str)
{
	char	**str_tab;
	int		i;
	int		j;
	int		start;
	int		end;

	i = 0;
	j = 0;
	if (str[0] == '$' && (str[1] == '\'' || str[1] == '\"'))
		str ++;
	str_tab = ft_calloc((count_word(str) + 1), sizeof(char *));
	if (!str_tab)
		return (NULL);
	while (str[i] && j < count_word(str))
	{
		start = start_of_qword(str, i);
		end = end_of_qword(str, start);
		str_tab[j] = ft_substr(str, start, end - start);
		while (str[i] && i < end)
			i++;
		j++;
	}
	return (str_tab);
}
