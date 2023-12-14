/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:24:32 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/27 17:24:47 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dump_del(t_list *garbage)
{
	if (garbage == NULL)
		return ;
	else
	{
		dump_del(garbage->next);
		free(garbage->content);
		free(garbage);
	}
}
