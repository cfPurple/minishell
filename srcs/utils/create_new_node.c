/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:02:17 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 11:02:19 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_new_node(char *str)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (0);
	node->word = str;
	node->next = NULL;
	return (node);
}
