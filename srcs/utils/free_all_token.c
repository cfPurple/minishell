/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:56:03 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:56:05 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*free_all_token(t_token **token)
{
	t_token	*tmp;

	while ((*token))
	{
		tmp = (*token);
		free((*token)->word);
		(*token) = (*token)->next;
		free(tmp);
	}
	token = NULL;
	return (NULL);
}
