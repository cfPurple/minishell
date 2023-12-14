/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:08 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:35:49 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_token_len(t_token *token)
{
	int	i;

	if (!token)
		return (0);
	i = 0;
	while (token)
	{
		++i;
		token = token->next;
	}
	return (i);
}
