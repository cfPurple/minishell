/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:55:43 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:50:18 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_of_word(char *str, int i)
{
	if (!str[i])
		return (i);
	if (ft_strchr("<|>", str[i]) != 0)
	{
		i++;
		if ((str[i - 1] != '|')
			&& (str[i] == '<' || str[i] == '>'))
			i ++;
		return (i);
	}
	while (str[i])
	{
		if (open_quote(str, i) == 0
			&& (str[i] == ' ' || ft_strchr("<|>", str[i]) != 0))
			break ;
		i++;
	}
	return (i);
}
