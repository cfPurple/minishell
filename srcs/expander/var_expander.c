/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:45:45 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_expander(char *str)
{
	char	**word_tab;
	char	**new_word_tab;
	char	*new_word;
	int		i;

	i = -1;
	if (ft_strchr(str, '$') == 0)
		return (ft_strdup(str));
	word_tab = dollar_word_to_tab(str);
	if (!word_tab)
		return (NULL);
	new_word_tab = ft_calloc(ft_tablen(word_tab) + 1, sizeof(char *));
	if (!new_word_tab)
		return (NULL);
	while (word_tab[++i])
	{
		if (word_tab[i][0] == '$' && ft_strlen(word_tab[i]) > 1)
			new_word_tab[i] = var_to_value(word_tab[i]);
		else
			new_word_tab[i] = ft_strdup(word_tab[i]);
		if (!new_word_tab[i])
			return (free_tabs(new_word_tab, word_tab), NULL);
	}
	new_word = join_str(new_word_tab);
	return (free_tabs(new_word_tab, word_tab), new_word);
}
