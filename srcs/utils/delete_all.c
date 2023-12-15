/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:55 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:26 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*delete_all(t_token **node)
{
	t_token	*tmp;

	while ((*node))
	{
		tmp = (*node);
		free((*node)->word);
		(*node) = (*node)->next;
		free(tmp);
	}
	node = NULL;
	return (NULL);
}
