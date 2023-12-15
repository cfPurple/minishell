/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/27 17:17:46 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dump_add(void *content, t_list *garbage)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_back(&garbage, new);
}

