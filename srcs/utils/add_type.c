/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:52:13 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:45:13 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_type(char *str, int last_token)
{
	if (ft_strlen(str) == 1 && (*str == '<' || *str == '>'
			|| *str == '|'))
	{
		if (*str == '<')
			return (R_IN);
		else if (*str == '>')
			return (R_OUT);
		else if (*str == '|')
			return (PIPE);
	}
	else
	{
		if (str[0] == '<' && str[1] == '<')
			return (HEREDOC);
		else if (str[0] == '>' && str[1] == '>')
			return (APPEND);
		else if (last_token == HEREDOC)
			return (LIMITOR);
		else if (last_token == APPEND || last_token == R_OUT
			|| last_token == R_IN)
			return (FD);
	}
	return (WORD);
}
