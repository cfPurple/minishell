/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:59:48 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:59:50 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_word(t_token *token, char *new_word)
{
	free(token->word);
	token->word = NULL;
	token->word = ft_strdup(new_word);
	free(new_word);
}
