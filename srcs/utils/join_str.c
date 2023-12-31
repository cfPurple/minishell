/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:39 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 18:30:25 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_str(char **str)
{
	int		i;
	char	*final_str;

	i = 0;
	final_str = ft_calloc(1, sizeof(char));
	if (!final_str)
		return (NULL);
	while (str[i])
	{
		final_str = join_str2(final_str, str[i], final_str);
		if (!final_str)
			return (NULL);
		i++;
	}
	return (final_str);
}
