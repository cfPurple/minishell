/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:45:45 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_expander(t_token *token)
{
	char	*new_word;

	if (ft_strchr(token->word, '$') != 0)
	{
		new_word = var_expander(token->word);
		if (!new_word)
			return (ERROR);
        replace_word(token, new_word);
	    return (SUCCESS);
	}
	else
		return (SUCCESS);
}