/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:04:33 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:03:54 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_value_len(char *var)
{
	int	i;
	int	val_len;

	val_len = 0;
	i = 0;
	while (var[i] != '=')
		i++;
	i++;
	while (var[i])
	{
		val_len++;
		i++;
	}
	return (val_len);
}
