/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qworld_explander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:45:45 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	qword_expander(t_token *token)
{
	char	**word_tab;
	char	**new_word_tab;
	char	*new_word;
	int		i;

	word_tab = qword_to_tab(token->word);
	if (!word_tab)
		return (ERROR);
	new_word_tab = ft_calloc(ft_tablen(word_tab) + 1, sizeof(char *));
	if (!new_word_tab)
		return (free_tab(word_tab), ERROR);
	i = -1;
	while (word_tab[++i])
	{
		if (quote_type(word_tab[i][0]) != SQUOTE)
			new_word_tab[i] = qvar_expander(word_tab[i]);
		else
			new_word_tab[i] = remove_quote(word_tab[i]);
		if (!new_word_tab[i])
			return (free_tabs(word_tab, new_word_tab), ERROR);
	}
	new_word = join_str(new_word_tab);
	free_tabs(word_tab, new_word_tab);
	return (replace_word(token, new_word), SUCCESS);
}
