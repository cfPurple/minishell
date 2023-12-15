/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_qword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:55:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:55:35 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_of_qword(char *str, int i)
{
    i++;
	while (str[i])
	{
		if (open_quote(str, i) == 1)
		{
			if (open_quote(str, i + 1) == 0)
				return (i + 1);
		}
		else if (str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
	}
	return (i);
}
