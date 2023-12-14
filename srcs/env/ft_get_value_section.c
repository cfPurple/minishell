/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_section.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:02:56 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:09:35 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value_section(char *var, char *value)
{
	int	value_len;
	int	i;
	int	j;

	value_len = ft_get_value_len(var);
	value = (char *)malloc(sizeof(char) * (value_len + 1));
	if (!value)
		return (NULL);
	i = ft_get_key_len(var) + 1;
	j = 0;
	while (var[i])
	{
		value[j] = var[i];
		j++;
		i++;
	}
	value[j] = '\0';
	return (value);
}

