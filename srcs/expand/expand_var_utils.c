/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:02:29 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/21 19:55:57 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_var_char(char c)
{
	if (ft_isalnum(c) != 0 || c == '_' || c == '?' || c == '$')
		return (true);
	return (false);
}

int	dollar_word_count(char *str)
{
	int	i;
	int	count;
	int	flag;

	flag = false;
	i = 0;
	if (*str == '$')
		count = 0;
	else
		count = 1;
	while (str[i])
	{
		if (str[i] == '$')
		{
			flag = true;
			count++;
		}
		else if (flag == true && is_var_char(str[i]) == false)
		{
			flag = false;
			count++;
		}
		i++;
	}
	return (count);
}

char	*expand_heredoc_var(char *line)
{
	char	*str;

	str = expand_var(line);
	free(line);
	return (str);
}
