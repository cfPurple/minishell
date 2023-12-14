/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:33:43 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:04:07 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key_section(char *var, char *key)
{
	int	key_len;
	int	i;

	key_len = get_key_len(var);
	key = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (i < key_len)
	{
		key[i] = var[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

