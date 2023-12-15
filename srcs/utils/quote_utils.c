/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:54:50 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/17 16:01:44 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote_heredoc(t_token *rdir)
{
	t_token	*ptr;

	ptr = rdir;
	while (ptr != 0)
	{
		if (ptr->type == LIMITOR && ft_strchr(ptr->word, '\'') == 0
			&& ft_strchr(ptr->word, '\"') == 0)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}
