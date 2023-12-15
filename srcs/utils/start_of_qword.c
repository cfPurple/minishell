/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_qword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:00:04 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 11:00:35 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_of_qword(char *str, int i)
{
	while (str[i])
	{
		if (open_quote(str, i) == 1)
		{
			if (open_quote(str, i + 1) == 1)
				return (i + 1);
		}
		else if (str[i] != '\'' || str[i] != '\"')
			break ;
		i++;
	}
	return (i);
}
