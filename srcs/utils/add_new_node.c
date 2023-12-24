/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:43:02 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:43:04 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_new_node(t_token *token, char *line)
{
	t_token	*new_node;

	new_node = create_new_node(line);
	if (!new_node)
		return (ERROR);
	token_add_back(&token, new_node);
	return (SUCCESS);
}
